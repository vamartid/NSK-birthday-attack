#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main ()
{
  std::unordered_map<std::string,std::vector<int>> mymap;

  std::vector<int> a={1,2,3};
  std::vector<int> b={3,3,3};

  std::cout << "a : "; 
  for (int i=0; i<a.size(); i++) 
      std::cout << a[i] << " "; 
  std::cout << std::endl; 

  std::cout << "b : "; 
  for (int i=0; i<b.size(); i++) 
      std::cout << b[i] << " "; 
  std::cout << std::endl; 

  mymap["a"] = a;
  mymap["b"] = a;
  a[1]++;

  std::cout << "mymap[a] : "; 
  for (int i=0; i<mymap["a"].size(); i++) 
      std::cout << mymap["a"][i] << " "; 
  std::cout << std::endl;

  std::cout << "mymap[b] : "; 
  for (int i=0; i<mymap["b"].size(); i++) 
      std::cout << mymap["b"][i] << " "; 
  std::cout << std::endl; 
  

  std::cout << "--test 1" << std::endl;
  if(!mymap["a"].empty()){
    std::cout << "test_1" << std::endl;
    if(mymap["a"]==std::vector<int>({1,2,3})){
      std::cout << "test_2" << std::endl;
    }
  }

  std::cout << "--test 2" << std::endl;
  if(!mymap["b"].empty()){
    std::cout << "test_1" << std::endl;
    if(mymap["b"]==std::vector<int>({3,3,3})){
      std::cout << "test_2" << std::endl;
    }
  }

  std::cout << "--test 2.2" << std::endl;
  if(!mymap["b"].empty()){
    std::cout << "test_1" << std::endl;
    if(mymap["b"]==mymap["a"]){
      std::cout << "test_2" << std::endl;
    }
  }


  std::cout << "--test 3" << std::endl;
  if(!mymap["c"].empty()){
    std::cout << "test_1" << std::endl;
    if(mymap["c"]==mymap["a"]){
      std::cout << "test_2" << std::endl;
    }
  }

  return 0;
}