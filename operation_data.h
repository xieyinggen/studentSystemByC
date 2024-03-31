//
// Created by xiada on 2024/3/30.
//

#ifndef UNTITLED16_OPERATION_DATA_H
#define UNTITLED16_OPERATION_DATA_H

void appendMessageData(Student *array,StudentScore *arrayScore, int size,Student payload){
    array[size]=payload;
    arrayScore[size].Chinese=0;
    arrayScore[size].Math=0;
    arrayScore[size].English=0;
    arrayScore[size].Sport=0;
}

void deleteMessageData(Student *array, int subscript, int elementSize){
    for (int i = subscript; i < elementSize; ++i) {
        array[i]=array[i+1];
    }
}

void replaceData(Student *array, int subscript){
    int userChoice;
    printf("请输入您需要修改学生的信息****1表示学号\t2表示姓名\t3表示班级\t4表示身份证号\t5表示年龄\t6表示地址\t7表示邮箱: ");
    scanf("%d",&userChoice);
    switch (userChoice) {
        case REPLACE_ID:{
            char *id;
            id=(char *) malloc(sizeof (char)*DEFINE_SPACE);
            printf("请输入学号: ");
            scanf("%s",id);
            array[subscript].id=id;
            break;
        }
        case REPLACE_NAME:{
            char *name;
            name=(char *) malloc(sizeof (char) * DEFINE_SPACE);
            printf("请输入姓名: ");
            scanf("%s", name);
            array[subscript].name=name;
            break;
        }
        case REPLACE_CLASSNAME:{
            char *classname;
            classname=(char *) malloc(sizeof (char) * DEFINE_SPACE);
            printf("请输入班级: ");
            scanf("%s", classname);
            array[subscript].classname=classname;
            break;
        }
        case REPLACE_UID:{
            char *uid;
            uid=(char *) malloc(sizeof (char) * DEFINE_SPACE);
            printf("请输入身份证号: ");
            scanf("%s", uid);
            array[subscript].uid=uid;
            break;
        }
        case REPLACE_AGE:{
            int age;
            printf("请输入年龄: ");
            scanf("%d", &age);
            array[subscript].age=age;
            break;
        }
        case REPLACE_ADDRESS:{
            char *address;
            address=(char *) malloc(sizeof (char) * DEFINE_SPACE);
            printf("请输入地址: ");
            scanf("%s", address);
            array[subscript].address=address;
            break;
        }
        case REPLACE_EMAIL:{
            char *email;
            email=(char *) malloc(sizeof (char) * DEFINE_SPACE);
            printf("请输入邮箱: ");
            scanf("%s", email);
            array[subscript].email=email;
            break;
        }
    }
}

void appendScoreData(StudentScore *array, int subscript,StudentScore payload){
    array[subscript]=payload;
}

void deleteScoreData(StudentScore *array,int subscript){
    int userChoice;
    printf("请输入需要删除的学科****1表示语文\t2表示数学\t3表示英语\t4表示体育\t5表示全部: ");
    scanf("%d",&userChoice);
    switch (userChoice) {
        case DELETE_CHINESE:{
            array[subscript].Chinese=0;
            break;
        }
        case DELETE_MATH:{
            array[subscript].Math=0;
            break;
        }
        case DELETE_ENGLISH:{
            array[subscript].English=0;
            break;
        }
        case DELETE_SPORT:{
            array[subscript].Sport=0;
            break;
        }
        case DELETE_ALL_SUBJECT:{
            array[subscript].Chinese=0;
            array[subscript].Math=0;
            array[subscript].English=0;
            array[subscript].Sport=0;
            break;
        }
    }
}

void replaceScoreData(StudentScore *array,int subscript) {
    int userChoice;
    printf("请输入需要修改的学科****1表示语文\t2表示数学\t3表示英语\t4表示体育\t5表示全部: ");
    scanf("%d", &userChoice);
    switch (userChoice) {
        case DELETE_CHINESE: {
            float Chinese;
            printf("请输入修改后的成绩: ");
            scanf("%f",&Chinese);
            array[subscript].Chinese = Chinese;
            break;
        }
        case DELETE_MATH: {
            float Math;
            printf("请输入修改后的成绩: ");
            scanf("%f",&Math);
            array[subscript].Math = Math;
            break;
        }
        case DELETE_ENGLISH: {
            float English;
            printf("请输入修改后的成绩: ");
            scanf("%f",&English);
            array[subscript].English = English;
            break;
        }
        case DELETE_SPORT: {
            float Sport;
            printf("请输入修改后的成绩: ");
            scanf("%f",&Sport);
            array[subscript].Sport = Sport;
            break;
        }
        case DELETE_ALL_SUBJECT: {
            float Chinese,Math,English,Sport;
            printf("请输入修改后的语文成绩: ");
            scanf("%f",&Chinese);
            array[subscript].Chinese = Chinese;
            printf("请输入修改后的数学成绩: ");
            scanf("%f",&Math);
            array[subscript].Math = Math;
            printf("请输入修改后的英语成绩: ");
            scanf("%f",&English);
            array[subscript].English = English;
            printf("请输入修改后的体育成绩: ");
            scanf("%f",&Sport);
            array[subscript].Sport = Sport;
            break;
        }
    }
}

void exchangeClass(Student *array,char *newClassName,int subscript){
    array[subscript].classname=newClassName;
}

#endif //UNTITLED16_OPERATION_DATA_H