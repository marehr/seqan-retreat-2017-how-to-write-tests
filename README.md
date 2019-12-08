Please don't use this! This was an example repository for a SeqAn Retreat in March 2017. The purpose was to pitch google test, explain how google test is working, how one can use it and have a small hands on session. We use google test in [seqan3](https://github.com/seqan/seqan3), so if you want to see more example have a look in that repository.

---

We are using
**[googletest](https://github.com/google/googletest/blob/master/googletest/docs/Documentation.md)**!
And all are like *YEAH?*

First things first, does it work for you?

```sh
git clone https://github.com/marehr/seqan-retreat-2017-how-to-write-tests
.git

cd seqan-retreat-2017-how-to-write-tests

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
* What happened? Did the `tdd` approach cover everything?
