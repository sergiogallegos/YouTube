import numpy as np

def bow(t,v):
    token_dict = {} # create a dictionary
    for token in t: # token in dictionary
        if token in token_dict:
            token_dict[token] += 1 # if exist add 1
        else:
            token_dict[token] = 1  # if is first set equal to 1
    bow_vector = [token_dict.get(word, 0) for word in v] # create a list from dictionary
    return np.array(bow_vector) # return as array

def most_common(vocabulary, bag_of_words):
    bow_array = np.array(bag_of_words) # Convert to numpy array if needed
    word_counts = bow_array.sum(axis=0) # Sum each column to get total count per word across all documents
    max_index = np.argmax(word_counts[1:]) + 1 # Find the index with max count
    return vocabulary[max_index]

def main():
    # testing bow function
    V = ['deep', 'learning', 'neural', 'network']
    t = ['deep', 'learning']
    result = bow(t, V)
    print(result)

    # testing most_common
    vocabulary = ['UNKNOWN', 'deep', 'learning', 'neural', 'network']
    bag_of_words = [[0,1,2,0,1],[0,0,3,1,0],[0,1,1,0,0]]
    print(most_common(vocabulary, bag_of_words))


if __name__ == "__main__":
    main()
