# NSK birthday attack

We provide an improved and parallel implementation of a previous attack to Naccache-Stern knapsack (NSK) cryptosystem.

Ref. : Birthday type attacks to the Naccache-Stern Knapsack cryptosystem, Information Proc.Letters (Elsevier) Vol. 138, October 2018, Pages 39-43 IPL, joint work with M. Anastasiadis and N. Chatzis.

One folder has the serial version and the master has the parallel

## Getting Started

You will need to have installed the libraries in Built With section, have the latest g++ version to build the project.

To build the serial version of this attack
```
make all2
```
To build the parallel version of this attack
```
make all2par
```
This make argument builds the project and we get multy.out which is the executable and it is build with main2.cpp.

It is possible to build the project so that it will only attempt one round of this attack.
This is available for testing purposes.
To build the serial version of this attack for one round attempt
```
make all
```
To build the parallel version of this attack for one round attempt
```
make allpar
```

### Running the attack

You can view how to use the arguments of the executable like this. 
```
./multy.out --help
```

After reading the help output. We can run for example an attack to a message with hamming 7 and p of 2048-bits and b=n/2-3  like this.
```
./multy.out -p 3 --ham 7 --sb 3
```

## Built With

* [Openmp](https://www.openmp.org/) - API specification for parallel programming
* [GMP](https://gmplib.org/) - Arithmetic without limitations
* [OpenSSL](https://www.openssl.org/) - Used for the md5-hashes
* [args](https://github.com/Taywee/args) - Argument parsing library

## Parallelism
After experiments we calculated that the cost of the computation to construct the
sets Ui,hi , is the most intensive part of the algorithm.
In this implementation we parallelized the creation of the elements of the sets Ui,hi, so that each thread will have to calculate one element and add it to the Ui,hi set.

Also we use the [libstdc++ parallel mode](https://gcc.gnu.org/onlinedocs/libstdc++/manual/parallel_mode_using.html) for the functions sort,intersection and find_if.

## Authors

* **Vasileios Martidis**

## License

This project is licensed under the GPLv3 License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* [First version of this attack](https://github.com/drazioti/python_scripts/tree/master/paper_ns)

