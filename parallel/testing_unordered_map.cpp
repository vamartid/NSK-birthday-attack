#include <iostream>
#include "unordered_map"

# include <omp.h>//openmp
#include <gmpxx.h>//gmp c++ interface
#include "Utilities.h"
#include "Combinations.h"

int main()
{

    int len = 20;
    int ham = 3;

    std::unordered_map < std::string, std::vector<short> > umap;


    // cout<<"n="<<len<<" h= "<<ham<<endl;
    Combinations* c_obj=new Combinations(len,ham);//obj which calc next comp
    // mpf_t to_be_multiplied_f;
    //calc nwh
    mpz_class number_of_cmb;//declare
    unsigned long long number_of_cmb_ull;//var which will take vallue from number of cmb
    c_obj->get_size(number_of_cmb);//set size of max compinations
    number_of_cmb_ull=mpz_2_ull(number_of_cmb);//set ull from mpz
    #pragma omp parallel for num_threads(4)
    for(unsigned long long i=0;i<number_of_cmb_ull;i++){
        //init/declare vars
        // std::string md5f12;         // md5 string to be added to the pair
        std::vector<short> cmb;
        #pragma omp critical
        cmb = c_obj->next_combination();//set the cmb which is the next combination
        // calc digest
        std::string md5 = prod_of_f2_when_c_bigger_1(cmb,L,p,c);
        #pragma omp critical
        umap[md5]=cmb;
    }    
    //clear combinations obj
    delete c_obj;


    for (auto x: umap){
        std::cout << x.first<<" "<<x.second.to_str() <<std::endl;
    }
    
    return 0;
}