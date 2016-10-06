import json
from random import shuffle

class Question:
    def __init__(self, title, text, topic=''):
        self.title = title
        self.text = text
        self.topic = topic

    def settopic(self,topic):
        self.topic = topic

class BayesClassifier:
    def __init__(self):
        self.testcases = []     #All example documents
        self.totalcounts = {}   #Number of times each word appears in all documents
        self.topiccounts = {}   #Number of times each word appears in each topic
        self.topics = {}        #Number of documents for each topic
        self.trainingsize = 0   #Number of test cases to use for training
        self.verifysize = 0     #Number of test cases to use for verification
        self.verifyratio = 0.05 #Portion of test cases to use for verification

    def addcase(self, case):
        self.testcases.append(case)

    def train(self):
        count = 0
        correctcount = 0
        testcount = 0

        shuffle(self.testcases)
        
        for case in self.testcases:
            count += 1
            if count > self.trainingsize:
                result = max(self.classify(case))
                testcount += 1
                if result[1]==case.topic:
                    correctcount += 1
                #print case.topic,result,result[1]==case.topic
            else:
                for word in case.title.split():
                    if word in self.totalcounts:
                        self.totalcounts[word] += 1
                    else:
                        self.totalcounts[word] = 1

                    if case.topic not in self.topiccounts:
                        self.topiccounts[case.topic] = {}

                    if word in self.topiccounts[case.topic]:
                        self.topiccounts[case.topic][word] += 1
                    else:
                        self.topiccounts[case.topic][word] = 1

                if case.topic in self.topics:
                    self.topics[case.topic] += 1
                else:
                    self.topics[case.topic] = 1

                    #totalwords += 1

        print "Accuracy:",float(correctcount)/testcount
        #print self.topiccounts

    def gettrainingset(self,infilename, outfilename):
        infile = open(infilename, 'r')
        self.numcases = int(infile.readline())

        self.verifysize = int(self.verifyratio * self.numcases)
        self.trainingsize = self.numcases - self.verifysize
        
        for line in infile:
            self.addcase(decodejson(line))

        i = 0
        outfile = open(outfilename, 'r')
        for line in outfile:
            self.testcases[i].settopic(line)
            i+=1

    def pwordgiventopic(self,topic,word):
        #(<#times word appears in the topic> + 1) / ( <# all words in the topic> + <# unique words in the topic> )
        #print word,self.topiccounts[topic],
        if word not in self.topiccounts[topic]:
            count = 0
        else:
            count = self.topiccounts[topic][word]

        result = (count + 1.0) / float(sum(self.topiccounts[topic].itervalues()) + len(self.topiccounts[topic]))

        #print result
        return result

    def ptopicgivenword(self,topic,word):
        pass

    def ptopic(self, topic):
        return float(self.topics[topic]) / len(self.testcases)

    def classify(self, question):
        return [( self.ptopic(topic)*reduce(lambda x, y: x * y, [self.pwordgiventopic(topic, word) for word in question.title.split()]), topic ) for topic in self.topics]

def decodejson(text):
    temp = json.loads(text)
    return Question(temp['question'],temp['excerpt'])

if __name__=='__main__':
    bc = BayesClassifier()
    bc.gettrainingset('input00.txt','output00.txt')
    bc.train()
