//
// Created by xiada on 2024/3/30.
//

#ifndef UNTITLED16_STRUCT_VERIABLE_H
#define UNTITLED16_STRUCT_VERIABLE_H

#define DEFINE_SPACE 30

typedef struct StudentScore{
    float Chinese;
    float Math;
    float English;
    float Sport;
}StudentScore;

typedef struct Student{
    char *id;
    char *name;
    char *classname;
    char *uid;
    int age;
    char *address;
    char *email;
    StudentScore *score;
}Student;

#endif //UNTITLED16_STRUCT_VERIABLE_H
