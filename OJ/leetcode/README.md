leetcode-cplusplus
==================
My C++ Project for [LeetCode Online Judge](http://oj.leetcode.com/).

You may use it as a scaffolding for your own project. 

You may also refer to my answers in the src folder, and improve the algorithms.

All unit tests are provided based on the google test framework.

## Requirements
* gcc >= 4.8
or
* clang >= 3.1


## Get Started
```bash
chmod u+x bootstrap.sh
./bootstrap
```
## Generate a file for a question

```bash
./question.sh create some_question 
```

The above command will generate three file: 

`src/some_question/some_question.h`: the solution you need to implement;

`src/some_question/README.md`: write the description of the question and your thoughts about the solution;

`test/some_question_test.cc`: you can write your unit tests here.

## Build

If you are not using `g++`, you need to set `CXX` to the compiler which you are using. For example, `export CXX=clang++`.

After that, you can use the following command to build and test.
```bash
make
```

## I will move all my previous answers into the src folder soon.
