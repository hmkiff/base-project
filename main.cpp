#include <iostream>
#include <cstdlib>

int primes[1000];
int pass_count;

int main(){
    primes[0] = 2;
    int primes_size = 1;
    std::cout << "Hello World" << std::endl;
    for(int i = 3; i<1001; i++){
        pass_count = 0;
        for(int j = 0; j < primes_size; j++){
            if(primes[j] > i/2){
                pass_count = primes_size;
                break;
            }
            std::cout << "Is " << i <<  " divisible by " << primes[j] << "? " << (i%primes[j] == 0) << std::endl;
            if((i%primes[j]) == 0){
                break;
            }
            else{
                pass_count++;
            }
        }
        if(pass_count == primes_size){
            primes[primes_size] = i;
            primes_size++;
            std::cout << i << " is Prime!" << std::endl;
        }
        
    }
    std::cout << "All the primes from 0 to 10000!" << std::endl;
    for(int index = 0; index < primes_size; index++){
        std::cout << primes[index] << std::endl;
    }
    return 0;
}