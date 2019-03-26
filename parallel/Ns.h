// Ns.h

#ifndef Ns_H
#define Ns_H

#include <iostream> //cout
// #include <algorithm>// std::random_shuffle
// for parallel
#include<parallel/algorithm>
# include <omp.h>//openmp
// for parallel end
#include <math.h>   //floor
#include <gmpxx.h>//gmp c++ interface
using std::cout;
using std::cerr;
using std::endl;
using std::fixed;
using std::rand;
using std::srand;
using std::random_shuffle;
using std::nothrow;
// for parallel
using __gnu_parallel::find_if;
// for parallel end
#include "Utilities.h"
#include "Combinations.h"

class Ns{
    public:
        // Constructor-Destructor
        Ns(); //constructor of Ns obj
        ~Ns(); //destructor of Ns obj deletes primes array
        // Other public functions
        /**
         * init vallues of p,q,n,s according to lenp & call init function to set u
         * s and p are selected so that gcd(p-1,s)==1
         */
        void choose_pk_sk(int,mpz_class&,mpz_class&,unsigned int&,mpz_class*&,mpz_class&); //init vars
        /**
         * encrypt message m by using public key and set c
         */
        void encrypt(mpz_class&,mpz_class,mpz_class,mpz_class*); //encrypt message
        /**
         * decrypt cyphertext c by using public and secret key and set m 
         */
        void decrypt(mpz_class&,mpz_class,unsigned int,mpz_class,mpz_class); //decrypt message
        /**
         * calculate the hamming weight of the mpz number
         */
        int popcount(mpz_class,int);// calculate the hamming weight of the mpz number
        /**
         * I1 I2 generator
         */
        void gen(unsigned int,double,int,mpz_class,mpz_class*,int*&,int*&,mpz_class*&,mpz_class*&,int&,int&,bool);
        /**
         * NSK attack function
         */
        bool attack(unsigned int,double,mpz_class,mpz_class,int,mpz_class,int,int*,int*,mpz_class*,mpz_class*,int,int);
    
    private: 
        // Private fields 
        mpz_class *primes; //primes ptr for the array
        // Private functions
        /**
         * sets the prime array with the first n primes
         */
        void set_primes_mpz(int); //init primes
        /**
         * init the u list by caluclating the prod
         */
        void init(mpz_class,mpz_class,mpz_class*&,unsigned int); //init u
        /**
         * This function set up the M sets with pairs 
         * of which each one has two vallues
         * a mpz_class number with certain hamming weight and
         * a string with the 12 first from hex repr from the md5 digest of
         * the prod calculation according to the mpz_number on base of 2
         * 
         * This is the function which is creating  the sets with parallelism 
         * Each thread takes a combination object to calculate the according prod
         * and generate the pair needed.When after the calculation it will add
         * the pair to the set.
         */
        void func2(std::vector <std::pair <std::string,std::vector<short>>>&,mpz_class*&,int,int,mpz_class,mpz_class); //init M lists
        /**
         * calculate prod -exp
         */
        std::string prod_of_f2_when_c_bigger_1(std::vector<short> cmb,mpz_class *&L,mpz_class& p,mpz_class& c);
        /**
         * calculate prod
         */
        std::string prod_of_f2_when_c_not_bigger_1(std::vector<short> cmb,mpz_class *&L,mpz_class& p,mpz_class& c);
        /**
         *  Set res vallue to the Modular Inverse of number
         *  res = num ^ -1 MOD p
         */
        void custom_mulinv(mpz_class &res,mpz_class num,mpz_class p);
        /**
         *  Set res vallue to the  
         *  res = base ^ exp MOD p
         *  if exp is negative handle it like Modular Inverse
         *  else handle it like mod
         */
        void modd_mpz_class_ui(mpz_class &res,mpz_class base,long int exp,mpz_class mod);
        /**
         * Set mpz_class msg as the message calculated from the prod
         *
         */
        void construct_msg_mpz(mpz_class &,int*&,std::vector<short>,int&,int*&,std::vector<short>,int&);
};
#endif