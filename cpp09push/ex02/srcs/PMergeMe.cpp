/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 23:25:03 by lboudjel          #+#    #+#             */
/*   Updated: 2025/03/10 23:25:03 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/* jacobsthal : 0 1 1 3 5 11 21 43 ...
    J(0) = 0 && J(1) = 1
    -> J(n) = J(n-1) + 2×J(n-2) pour n ≥ 2 */
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
    Container mainContainer;
    std::vector<int> smallerValues, biggerValuesPosition;
    int oddNumber;
    bool hasOddNumber;

    createAndSortPairs<Container>(container, mainContainer, smallerValues, biggerValuesPosition, oddNumber, hasOddNumber);
    binaryInsertSort<Container>(mainContainer, smallerValues, biggerValuesPosition);
    
    container = mainContainer;
}

template <typename Container>
void PmergeMe::createAndSortPairs(Container &container, Container &mainContainer, std::vector<int> &smallerValues, std::vector<int> &biggerValuesPosition, int &oddNumber, bool &hasOddNumber) {
    if (container.size() <= 1)
        return;
    std::vector< std::pair<int, int> > pairs;
    oddNumber = -1;
    hasOddNumber = false;

    //si size est impair on stocke le dernier element
    if (container.size() % 2 != 0) {
        oddNumber = container[container.size() - 1];
        hasOddNumber = true;
    }

    //on cree les paires, a = petit / b = grand
    for (size_t i = 0; i < container.size() / 2; ++i) {
        int a = container[i * 2];
        int b = container[i * 2 + 1];
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    //on rappelle la fonction en recursif pour trier les elements les + grands tant quil y a des paires
    if (pairs.size() > 1) {
        Container biggerValues;
        for (size_t i = 0; i < pairs.size(); ++i)
            biggerValues.push_back(pairs[i].second); 
        fordJohnsonSort<Container>(biggerValues);
        mainContainer = biggerValues;
    }
    else if (pairs.size() == 1)
        mainContainer.push_back(pairs[0].second);

    /*on stocke maintenant les petits elements dans un vecteur et grace a biggerValueForPosition 
    (vecteur qui stocke les grands elements a leur position de depart non triee)
    on pourra retrouver leur paire pour faciliter l'insertion binaire du petit plus tard */
    for (size_t i = 0; i < pairs.size(); ++i) {
        smallerValues.push_back(pairs[i].first);
        biggerValuesPosition.push_back(pairs[i].second);
    }
    
    //si ya un impair on cherche sa position et on l'insere
    if (hasOddNumber) {
        int i = 0, size = mainContainer.size();
        while (i < size) {
            int half = (i + size) / 2;
            if (mainContainer[half] < oddNumber)
                i = half + 1;
            else 
                size = half;
        }
        mainContainer.insert(mainContainer.begin() + i, oddNumber);
    }
}

/* cette fonction sert a trouver ou vont les petites valeurs des paires puis les inserer
    on stock dans whereToInsertSmallValues les index ou on inserera la valeur dans le mainContainer
    -> les index sont trouves grace a la suite de jacobsthal qui va nous generer un ordre d'insertion 
   
    par exemple, pour jacobTotalValue = 11 et prevJacob = 5 on aura :
    1) 1e for loop on ajoute '10' dans whereToInsertSmallValues (a la suite des index deja stockes) 
        grace a la ligne -> whereToInsertSmallValues.push_back(jacobTotalValue - 1);
    2) puis dans la 2e for loop on a i = (jacobTotalValue - 2); i > (prevJacob - 1); -> on va iterer de 9 a 4 
        donc on ajoutera 9 8 7 6 5 mais pas 4 car 4 aura deja ete stocke auparavant 
    3) apres cette etape on aura whereToInsertSmallValues : [0, 2, 1, 4, 3, 10, 9, 8, 7, 6, 5].
        et donc le 1e element de smallValues sera inseree a la position 0 de mainContainer, 
        le 3e element sera a la positon 1 de mainContainer
        le 6e element en position 10, etc ...

    et pour inserer chaque element dans mainContainer on utilise la recherche binaire pour minimiser les coups
 */

template <typename Container>
void PmergeMe::binaryInsertSort(Container &mainContainer, const std::vector<int> &smallerValues, const std::vector<int> &biggerValuesPosition) {
    std::vector<int> whereToInsertSmallValues;
    whereToInsertSmallValues.push_back(0); 
    int jacobTotalValue, jacobsthalIndex = 1, prevJacob = 1;
    
    while (whereToInsertSmallValues.size() < smallerValues.size()) {
        jacobTotalValue = jacobsthalNumber(jacobsthalIndex + 1);
        if (jacobTotalValue - 1 < smallerValues.size() && std::find(whereToInsertSmallValues.begin(), whereToInsertSmallValues.end(), jacobTotalValue - 1) == whereToInsertSmallValues.end())
            whereToInsertSmallValues.push_back(jacobTotalValue - 1);
    
        for (int i = (jacobTotalValue - 2); i > (prevJacob - 1); --i) {
            if (i >= 0 && i < smallerValues.size() && std::find(whereToInsertSmallValues.begin(), whereToInsertSmallValues.end(), i) == whereToInsertSmallValues.end())
                whereToInsertSmallValues.push_back(i);
        }
        prevJacob = jacobTotalValue;
        jacobsthalIndex++;
    }

    //on insere les elements avec la binary search
    int index, value, size, mainContainerSize, toInsert, mid;
    for (int i = 0; i < whereToInsertSmallValues.size() && i < smallerValues.size(); ++i) {
        index = whereToInsertSmallValues[i];
        if (index < smallerValues.size()) {
            value = smallerValues[index];

            typename Container::iterator it = std::find(mainContainer.begin(), mainContainer.end(), biggerValuesPosition[index]);
            mainContainerSize = std::distance(mainContainer.begin(), it);
            toInsert = 0, size = mainContainerSize + 1;
            while (toInsert < size) {
                mid = (toInsert + size) / 2;
                if (mainContainer[mid] < value)
                    toInsert = mid + 1;
                else
                    size = mid;
            }
            mainContainer.insert(mainContainer.begin() + toInsert, value);
        }
    }
}
