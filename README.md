# DisorderHandlingSystem[![CMake](https://github.com/intellistream/ModernCPlusProjectTemplate/actions/workflows/cmake.yml/badge.svg?branch=main)] [![C++](https://img.shields.io/badge/-C++-3776AB?style=flat-square&logo=c++&logoColor=ffffff)](https://www.python.org/)
Implement of disorder handling of data stream from a ICDE2016 paper

## Paper Introduction

### ICDE2016 Paper： Quality-Driven Disorder Handling for M-way Sliding Window Stream Joins

![image](https://user-images.githubusercontent.com/105226542/217196933-3c82d383-2cff-4519-85f4-df7ce8955160.png)

https://arxiv.org/abs/1703.07617




### Main architecture
![image](https://user-images.githubusercontent.com/105226542/216963968-9ee72e72-3ddc-404f-8b45-119a0a136d1f.png)



### Main mathematical formulas


![image](https://user-images.githubusercontent.com/105226542/216964302-0ce5d0ea-0b6c-4f64-90be-53e912edc550.png)


![image](https://user-images.githubusercontent.com/105226542/216964340-1f2a175a-c8b8-4372-92a8-dd0433a3a046.png)

![image](https://user-images.githubusercontent.com/105226542/216964400-5ea4b7bb-b7a5-4546-850c-cdcfbefa8ee1.png)

![image](https://user-images.githubusercontent.com/105226542/218294983-d3591f8c-7909-49e9-b80b-904a6cb370a4.png)

![image](https://user-images.githubusercontent.com/105226542/218294986-83cb46fe-b649-4396-a28a-66c79c1aa2fc.png)

![image](https://user-images.githubusercontent.com/105226542/218295008-5e4b917b-2b81-4489-92b2-44e99d160c70.png)


## How to build

### Build in shell

```shell

mkdir build && cd build
cmake ..
make 
