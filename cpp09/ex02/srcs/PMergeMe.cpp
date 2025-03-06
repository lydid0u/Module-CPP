#include "PMergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(char **argv) {
    std::vector<int> beforeContainer;
    parsing(argv);
    for (int i = 0; argv[i]; i++)
        beforeContainer.push_back(atoi(argv[i]));
    printRange(beforeContainer, 1);

	//calling algorithm with vector container
    algorithm(argv, vector, vectorClockStart, vectorClockEnd);
    //calling algorithm with deque container
    algorithm(argv, deque, dequeClockStart, dequeClockEnd);

    printRange(vector, 0);
    std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << vectorClockEnd - vectorClockStart << " us" << std::endl;
    std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : " << dequeClockEnd - dequeClockStart << " us" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe&    PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        vector = other.vector;
        deque = other.deque;
        vectorClockStart = other.vectorClockStart;
        dequeClockStart = other.dequeClockStart;
        vectorClockEnd = other.vectorClockEnd;
        dequeClockEnd = other.dequeClockEnd;
    }
    return (*this);
}

template <typename T>
void    printRange(const T &container, bool before) {
	int i;
	if (before == true)
		std::cout << "Before : ";
	else
		std::cout << "After : ";
	for (i = 0; i < (int)container.size() - 1; i++)
		std::cout << container[i] << " ";
	if (i < (int)container.size())
		std::cout << container[i];
	std::cout << std::endl;
}

void    parsing(char **nbr) {
	for (int i = 0; nbr[i]; i++) {
		char *endptr;
        long nb = strtol(nbr[i], &endptr, 10);
        if (*endptr != '\0')
			throw std::invalid_argument("invalid input, value is not an int -> " + std::string(nbr[i]));
        if (nb < 0)
			throw std::invalid_argument("not a positive number -> " + std::string(nbr[i]));
        if (nb > INT_MAX || nb < INT_MIN)
			throw std::invalid_argument("number not in the range of an int  -> " + std::string(nbr[i]));
    }

    for (int i = 0; nbr[i]; i++) {
		long nb = strtol(nbr[i], NULL, 10);
        for (int j = i + 1; nbr[j]; j++) {
			if (nb == strtol(nbr[j], NULL, 10))
				throw std::invalid_argument("number found twice -> " + std::string(nbr[j]));
        }
    }
}

template <typename Container>
void PmergeMe::algorithm(char **nbr, Container &container, std::clock_t &start, std::clock_t &end) {
	start = std::clock();
	container.clear();
	for (int i = 0; nbr[i]; i++)
		container.push_back(atoi(nbr[i]));
	fordJohnsonSort<Container>(container);
	end = std::clock();
}

// jacobsthal : 0 1 1 3 5 11 22 ...
int jacobsthalNumber(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthalNumber(n - 1) + 2 * jacobsthalNumber(n - 2);
}

template <typename Container>
void PmergeMe::fordJohnsonSort(Container &container) {
    if (container.size() <= 1)
        return;
    std::vector< std::pair<int, int> > pairs;
    int oddNumber = -1;
    bool hasOddNumber = false;

    //si size impair, on stock le dernier element
    if (container.size() % 2 != 0) {
        oddNumber = container[container.size() - 1];
        hasOddNumber = true;
    }
    //on cree les pairs, a = petit / b = grand
    for (size_t i = 0; i < container.size() / 2; ++i) {
        int a = container[i * 2];
        int b = container[i * 2 + 1];
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    //on rappelle la fonction en recursive pour trier les element les + grands tant que ya des pairs
    Container mainChunk;
    if (pairs.size() > 1) {
        Container biggerValues;
        for (size_t i = 0; i < pairs.size(); ++i)
            biggerValues.push_back(pairs[i].second); 
        fordJohnsonSort<Container>(biggerValues);
        mainChunk = biggerValues;
    }
    else if (pairs.size() == 1)
        mainChunk.push_back(pairs[0].second);

    /* on stock mtn les petits elements dans un vecteur et grace a biggerValueForPosition (vecteur qui stock les grands elements a leur position de depart non trie)
    on pourra retrouver leur paire pour faciliter l'insertion binaire plus tard */
    std::vector<int> smallerValues;
    std::vector<int> biggerValuesForPosition;
    for (size_t i = 0; i < pairs.size(); ++i) {
        smallerValues.push_back(pairs[i].first);
        biggerValuesForPosition.push_back(pairs[i].second);
    }

    //si impair, on cherche sa position et on l'insere
    if (hasOddNumber) {
        int i = 0, size = mainChunk.size(), half;
        while (i < size) {
            int half = (i + size) / 2;
            if (mainChunk[half] < oddNumber)
                i = half + 1;
            else 
                size = half;
        }
        mainChunk.insert(mainChunk.begin() + i, oddNumber);
    }

    //Générer la séquence d'insertion basée sur Jacobsthal
    std::vector<int> IndexSmallValues;
    IndexSmallValues.push_back(0); 
    int jacobIndex = 1, prevJacob = 1;
    while (IndexSmallValues.size() < smallerValues.size()) {
        //Calculer le prochain nombre de Jacobsthal dans l'intervalle
        int jacob = jacobsthalNumber(jacobIndex + 1);

        if (jacob - 1 < smallerValues.size() && std::find(IndexSmallValues.begin(), IndexSmallValues.end(), jacob - 1) == IndexSmallValues.end())
            IndexSmallValues.push_back(jacob - 1);
        //Ajouter les indices entre le Jacobsthal précédent et le suivant, en ordre décroissant
        for (int i = jacob - 2; i > (int)prevJacob - 1; --i) {
            if (i >= 0 && (int)i < smallerValues.size() && std::find(IndexSmallValues.begin(), IndexSmallValues.end(), i) == IndexSmallValues.end())
                IndexSmallValues.push_back(i);
        }
        prevJacob = jacob;
        jacobIndex++;
    }

    //Insérer les éléments selon l'ordre de Jacobsthal
    for (int i = 0; i < IndexSmallValues.size() && i < smallerValues.size(); ++i) {
        int idx = IndexSmallValues[i];
        if (idx < smallerValues.size()) {
            //Valeur à insérer
            int value = smallerValues[idx];

            //Trouver l'index correspondant dans la chaîne principale
            typename Container::iterator it = std::find(mainChunk.begin(), mainChunk.end(), biggerValuesForPosition[idx]);
            int mainChunkPos = std::distance(mainChunk.begin(), it);

            //Chercher la position correcte en utilisant la recherche binaire
            int insertPos = 0, high = mainChunkPos + 1; //+1 car nous cherchons jusqu'à l'élément plus grand inclus

            while (insertPos < high) {
                int mid = (insertPos + high) / 2;
                if (mainChunk[mid] < value)
                    insertPos = mid + 1;
                else
                    high = mid;
            }

            //Insérer l'élément à la bonne position
            mainChunk.insert(mainChunk.begin() + insertPos, value);
        }
    }
    container = mainChunk;
}