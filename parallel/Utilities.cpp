// Utilities.cpp
#include "Utilities.h"

/**
 * take time and print
 */
double time_passed(time_t clock_begin){
	time_t clock_end = clock();//set end time
    //calculate the seconds and print them
    double seconds = ((double)clock_end-(double)clock_begin)/CLOCKS_PER_SEC;
    //std::fixed is for full pressition print
	return seconds;
	// cout << "Time : " << fixed << seconds <<"s" << endl;
}
/**
 * convert a char to a number
 */
int char_to_num(char c){
	static const int ZERO_ASCII=48;
	return c-ZERO_ASCII;
}
/**
 * convert mpz_class to unsinged long long int
 */
unsigned long long mpz_2_ull(mpz_class z){
	unsigned long long result=0;
	mpz_export(&result,0,-1,sizeof result,0,0,z.get_mpz_t());
	return result;
}
/**
 * number to first 6 of md5
 */
std::string to_md5_f6_str(mpz_class number){
	std::string input = number.get_str();
	const char* input_ch_Ar=input.c_str();
	unsigned char md5digest_ch_Ar[16];
	MD5_CTX ctx;
	MD5_Init(&ctx);
	MD5_Update(&ctx,input_ch_Ar,strlen(input_ch_Ar));
	MD5_Final(md5digest_ch_Ar,&ctx);
	
	char res_ch_Ar[6];
	std::string md5_string;
	for(int i=0;i<6;i++){
		sprintf(&res_ch_Ar[i*2],"%02x",(unsigned int)md5digest_ch_Ar[i]);
	}	
	// why capacity does not go smaller than 15? 
	//remember to check this please
	//cause os sso!
	// md5_string.reserve(12);
	md5_string.append(res_ch_Ar);
	// md5_string.resize(md5_string.size());
	// md5_string.shrink_to_fit();
	// cout    << " size:"     << md5_string.size()
	// 	<< " length:"   << md5_string.length()
	// 	<< " capacity:" <<md5_string.capacity()<<endl;
	
	// printf("1md5:%s\n",res_ch_Ar);
	return md5_string;
}
/**
 * return a random int smaller than int
 */
int random_function_test (int i) {
    return rand()%i;
}
/**
 * generate a random string of bits with certain hamming weight
 */
string msg_Gen(unsigned int len,unsigned int ham){
    string msg_char(len,'0');// create a string with len and only 0
    // if ham is zero
	if(ham!=0){
        unsigned int cur_ham = 1;
		msg_char[0]='1'; // set intentionaly last bit as 1
		if(ham!=1){
            do{
                // get a random pos
                unsigned int pos = rand()%len;
                if(msg_char[pos]=='0'){// if this pos is not 1 set it
                    msg_char[pos]='1';
                    //increase current ham
                    cur_ham++;
                }
            }while(cur_ham<ham);
        }
    }
    // cout<<msg_char<<endl;
    //create the number from the binary
    // mpz_class msg=mpz_class(msg_char,2);
    // cout<<msg.get_str(2)<<endl;
	// cout<<msg<<endl;
	return msg_char;
}
