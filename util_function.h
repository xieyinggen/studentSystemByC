//
// Created by xiada on 2024/3/30.
//

#ifndef UNTITLED16_UTIL_FUNCTION_H
#define UNTITLED16_UTIL_FUNCTION_H

Student* reverseIncrementArraySize(int size){
    return (Student *)malloc(sizeof (Student)*(size+INCREMENT_ARRAY_SIZE_COEFFICIENT));
}

Student* reverseDecrementArraySize(int size){
    return (Student *)malloc(sizeof (Student)*(size-DECREMENT_ARRAY_SIZE_COEFFICIENT));
}



void copy(Student *oldArray,int size,Student *targetArray){
    for (int index = 0; index < size; ++index) {
        targetArray[index]=oldArray[index];
    }
}

#endif //UNTITLED16_UTIL_FUNCTION_H
