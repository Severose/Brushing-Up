import string
import re

# Constants
punctuation = string.punctuation
digits = string.digits
topics = ['gis' , 'security' , 'photo' , 'mathematica' , 'unix' , 'wordpress' , 'scifi' , 'electronics' , 'android' , 'apple']

def rem( s , dataset ):
	string = dataset.find(s)
	dataset = dataset[:string] + " " + dataset[string+len(s):]
	return dataset

def readdata( dataset,train ):
	# Remove "title" words from each dataset
	if train :
		dataset = rem("topic", dataset)
	dataset = rem("question", dataset)
	dataset = rem("excerpt", dataset)

	# Remove string formatting characters
	while dataset.find("\\n") >= 0:
		dataset = rem("\\n", dataset)
	while dataset.find("\\r") >= 0:
		dataset = rem("\\r", dataset)
	while dataset.find("\\x") >= 0:
		dataset = rem("\\x", dataset)

	# Special treatment for special characters (instances of this/that and contractions)
	while dataset.find("/") >= 0:
		dataset = rem("/", dataset)
	while dataset.find("\'") >= 0:
		dataset = rem("\'", dataset)

	# Remove all but alphabet characters and separate the words
	regex = re.compile('[^a-zA-Z]')
	dataset = regex.sub(' ', dataset)
	dataset = ''.join([char.lower() for char in dataset if not char in (punctuation or digits)]).split()

	# For training data
	if train:
		# Get the current training set's topic ID and remove the topic word from the list
		topic = topics.index(dataset[0])
		dataset = dataset[1:]

		# Populate classify matrix with training data
		for word in dataset:
			if (len(word) > 3) and (word in classify[topic]):
				classify[topic][word] = classify[topic][word] + 1
			elif len(word) > 3:
				classify[topic][word] = 1
				unique[topic] = unique[topic] + 1
			total[topic] = total[topic] + 1

	# For input data
	else:
		probabilities = [0 for i in range(10)]
		for word in dataset:
			for i in range(10):
				if (len(word) > 3) and (word in prob[i]):
					probabilities[i] = probabilities[i] + prob[i][word]
 
		print topics[probabilities.index(max(probabilities))] 


	

# Open training file
filein = open('training.json', 'r')
first = True
train = True
trainingData = []
classify = []
total = []
unique = []
prob = []			# Word probabilities


# Initialize the classify matrix
for i in range(10):
	classify.append({})
	total.append(0)
	unique.append(0)
	prob.append({})

# Read training data from file
for dataset in filein:
	# Read the amount of training data in the file (first line)
	if first:
		trainingCount = dataset
		first = False

	else :
		readdata(dataset,train)

# We have the "trained" matrix
#TODO: Implement "learning" function
#print(classify[0])
for i in range(10):
	for key, value in classify[i].iteritems():
		prob[i][key] = (classify[i][key] + 1.0)/(total[i] + unique[i])

#(<Specific Word Count> + 1) / ( <Total Words in Topic> + <Unique Words in Topic> )
filein.close()

first = True
train = False
guess = ""
probabilities = []		# Probability for a set to be in each category

# Initialize the matrices
for i in range(10):
	probabilities.append(0)
	total.append(0)
	unique.append(0)
	prob.append({})

inputCount = int(raw_input())

# Read input data from file
for i in range(inputCount) :
	dataset = raw_input()
	readdata(dataset, train)