We are using
**[googletest](https://github.com/google/googletest/blob/master/googletest/docs/Documentation.md)**!
And all are like *YEAH?*

First things first, does it work for you?

```sh
git clone https://github.com/marehr/seqan3-test-example.git

cd seqan3-test-example

mkdir build
cd build

cmake -DCMAKE_CXX_COMPILER=`which g++-7` ../test

make -j

ctest .
```

## Please, listen to the introduction?!

## Now it's your turn!

* Implement `is_power_of_two` in `test/basic/integral_types_test.cpp`
* Add new types like `uint16_t` and `uint32_t`
* What happened? Did the `tdd` approach cover everything
