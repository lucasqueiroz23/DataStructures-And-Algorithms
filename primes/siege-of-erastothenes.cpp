#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

std::vector<int> erastothenes(int limit){

    std::vector<int> primes;
    bool visited[limit + 1];

    for(int i = 0; i < limit + 1; i++) 
        visited[i] = false;

    visited[0] = true;
    visited[1] = true;

    for(int number = 1; number <= limit; number++) {
        int prime = number - 1;

        // number is not prime
        if(visited[prime]) 
            continue;

        primes.push_back(prime);
        int i = 2;

        while(i * prime <= limit) {
            visited[i*prime] = true;
            i++;
        }
    }

    if(!visited[limit]) primes.push_back(limit);

    return primes;
}

int main(int argc, char** argv) {

    if(argc != 2) {
        std::cout << "error: program should be called with two arguments.\nRun: ./siege <number>\n";
        exit(1);
    }

    int limit = atoi(argv[1]);

    for(auto prime : erastothenes(limit)) 
        std::cout << prime << "\n";
    return 0;
}
