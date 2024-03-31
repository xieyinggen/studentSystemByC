#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "static_veriable.h"
#include "struct_veriable.h"
#include "watcher.h"
#include "util_function.h"
#include "operation_data.h"

Student *studentList=NULL;
StudentScore *studentScoreList;
int arraySize=INCREMENT_ARRAY_SIZE_COEFFICIENT;
int elementSize=0;

Student *initList();
StudentScore *initScoreList();
void watchEffect();
void appendMessage(Student payload);
void deleteMessage(int subscript);
void replaceMessage(int subscript);
void appendScore(StudentScore payload,int subscript);
void deleteScore(int subscript);
void replaceScore(int subscript);
void doubleShift(char *newClassname,int subscript);
void showAllStudents();

int main() {
    studentList=initList();
    studentScoreList=initScoreList();
    watchEffect();
    return 0;
}

Student *initList(){
    return (Student *) malloc(sizeof (Student)*INCREMENT_ARRAY_SIZE_COEFFICIENT);
}

StudentScore *initScoreList(){
    return (StudentScore *) malloc(sizeof (StudentScore)*INCREMENT_ARRAY_SIZE_COEFFICIENT);
}

void watchEffect(){
    printf("****欢迎使用学生管理系统****\n");
    int userAction;
    while (true){
        printf("****请输入您想实行的操作****\n");
        printf("****0表示退出系统\t1表示添加学生的信息\t2表示删减学生的信息\t3表示修改学生的信息\t4表示添加学生的成绩\t5表示删除学生的成绩\t6表示修改学生的成绩\t7表示合班\t8表示查看学生的成绩与信息: ");
        scanf("%d",&userAction);
        switch (userAction) {
            case END_ACTION:{
                printf("感谢您的使用,如果您在使用过程中遇到什么问题,请联系手机号131********,我们期待您为我们提供宝贵的建议。");
                return;
            }
            case INCREMENT_MESSAGE_ACTION:{
                char *id,*name,*classname,*uid,*address,*email;
                Student *student=(Student *) malloc(sizeof (Student));
                int age,userChoice;
                id=(char *) malloc(sizeof (char)*DEFINE_SPACE);
                name=(char *) malloc(sizeof (char)*DEFINE_SPACE);
                classname=(char *) malloc(sizeof (char)*DEFINE_SPACE);
                uid=(char *) malloc(sizeof (char)*DEFINE_SPACE);
                address=(char *) malloc(sizeof (char)*DEFINE_SPACE);
                email=(char *) malloc(sizeof (char)*DEFINE_SPACE);
                printf("请输入学生的姓名: ");
                scanf("%s",name);
                student->name=name;
                printf("请输入学生的学号: ");
                scanf("%s",id);
                student->id=id;
                printf("请输入学生的班级: ");
                scanf("%s",classname);
                student->classname=classname;
                printf("请输入学生的身份证号: ");
                scanf("%s",uid);
                student->uid=uid;
                printf("请问还需继续完善学生的全部信息吗? 需要请输入除0的任意数,不需要请输入0: ");
                scanf("%d",&userChoice);
                if(userChoice){
                    printf("请输入学生的年龄: ");
                    scanf("%d",&age);
                    student->age=age;
                    printf("请输入学生的地址: ");
                    scanf("%s",address);
                    student->address=address;
                    printf("请输入学生的邮箱: ");
                    scanf("%s",email);
                    student->email=email;
                } else{
                    student->age=0;
                    student->address="无";
                    student->email="无";
                }
                appendMessage(*student);
                break;
            }
            case DECREMENT_MESSAGE_ACTION:{
                printf("请输入被删除学生的学号: ");
                char *id;
                id=(char *) malloc(sizeof (char)*DEFINE_SPACE);
                scanf("%s",id);
                for (int i = 0; i < elementSize; ++i) {
                    if(strcmp(studentList[i].id,id)==0){
                        deleteMessage(i);
                        break;
                    } else if(i==elementSize-1){
                        printf("您输入的学号不存在\n");
                    }
                }
                break;
            }
            case REPLACE_MESSAGE_ACTION:{
                printf("请输入需要修改信息的学生的学号(若您需要修改的是学生的学号,可通过查看学生信息获取该学生的学号): ");
                char *id;
                id=(char *) malloc(sizeof (char)*DEFINE_SPACE);
                scanf("%s",id);
                for (int i = 0; i < elementSize; ++i) {
                    if(strcmp(studentList[i].id,id)==0){
                        replaceMessage(i);
                        break;
                    } else if(i==elementSize-1){
                        printf("您输入的学号不存在\n");
                    }
                }
                break;
            }
            case INCREMENT_SCORE_ACTION:{
                float Chinese,Math,English,Sport;
                char *id;
                id=(char *) malloc(sizeof (char)*DEFINE_SPACE);
                StudentScore *student=(StudentScore *) malloc(sizeof (StudentScore));
                printf("请输入被添加成绩学生的学号: ");
                scanf("%s",id);
                printf("请输入语文成绩: ");
                for (int i = 0; ; ++i) {
                    scanf("%f",&Chinese);
                    if(Chinese<=SCORE_MAIN_SUBJECT_MAX&&Chinese>=SCORE_MAIN_SUBJECT_MIN){
                        break;
                    } else{
                        printf("输入成绩不能超过0——100这个区间,请重新输入: ");
                    }
                }
                student->Chinese=Chinese;
                printf("请输入数学成绩: ");
                for (int i = 0; ; ++i) {
                    scanf("%f",&Math);
                    if(Math<=SCORE_MAIN_SUBJECT_MAX&&Math>=SCORE_MAIN_SUBJECT_MIN){
                        break;
                    } else{
                        printf("输入成绩不能超过0——100这个区间,请重新输入: ");
                    }
                }
                student->Math=Math;
                printf("请输入英语成绩: ");
                for (int i = 0; ; ++i) {
                    scanf("%f",&English);
                    if(English<=SCORE_MAIN_SUBJECT_MAX&&English>=SCORE_MAIN_SUBJECT_MIN){
                        break;
                    } else{
                        printf("输入成绩不能超过0——100这个区间,请重新输入: ");
                    }
                }
                student->English=English;
                printf("请输入体育成绩: ");
                for (int i = 0; ; ++i) {
                    scanf("%f",&Sport);
                    if(Sport<=SCORE_PE_MAX&&Sport>=SCORE_PE_MIN){
                        break;
                    } else{
                        printf("输入成绩不能超过0——30这个区间,请重新输入: ");
                    }
                }
                student->Sport=Sport;
                for (int i = 0; i < elementSize; ++i) {
                    if(strcmp(studentList[i].id,id)==0){
                        appendScore(*student,i);
                        break;
                    } else if(i==elementSize-1){
                        printf("您输入的学号不存在\n");
                    }
                }
                break;
            }
            case DECREMENT_SCORE_ACTION:{
                char *id;
                id=(char *) malloc(sizeof (char)*DEFINE_SPACE);
                printf("请输入被删除成绩的学生的学号");
                scanf("%s",id);
                for (int i = 0; i < elementSize; ++i) {
                    if(strcmp(studentList[i].id,id)==0){
                        deleteScore(i);
                        break;
                    } else if(i==elementSize-1){
                        printf("您输入的学号不存在: ");
                    }
                }
                break;
            }
            case REPLACE_SCORE_ACTION:{
                char *id;
                id=(char *) malloc(sizeof (char)*DEFINE_SPACE);
                printf("请输入需要修改成绩的学生的学号");
                scanf("%s",id);
                for (int i = 0; i < elementSize; ++i) {
                    if(strcmp(studentList[i].id,id)==0){
                        replaceScore(i);
                        break;
                    } else if(i==elementSize-1){
                        printf("您输入的学号不存在: ");
                    }
                }
                break;
            }
            case DOUBLE_SHIFT_ACTION: {
                char *oldClassname,*newClassname;
                int state=0;
                oldClassname=(char *) malloc(sizeof (char) * DEFINE_SPACE);
                newClassname=(char *) malloc(sizeof (char) * DEFINE_SPACE);
                printf("请输入要合并到的班级: ");
                scanf("%s",newClassname);
                printf("请输入被合并的班级: ");
                scanf("%s",oldClassname);
                for (int i = 0; i < elementSize; ++i) {
                    if(strcmp(studentList[i].classname,oldClassname)==0){
                        doubleShift(newClassname,i);
                        state=1;
                        continue;
                    } else if(i==elementSize-1&&state==0){
                        printf("您输入的班级不存在: ");
                    }
                }

                break;
            }
            case EXAMINE_ACTION:{
                showAllStudents();
            }
        }
    }
}

void appendMessage(Student payload){
    if(watcherSizeAppend(arraySize,elementSize)){
        appendMessageData(studentList, studentScoreList,elementSize, payload);
    } else{
        Student *newStudentList= reverseIncrementArraySize(arraySize);
        copy(studentList,elementSize,newStudentList);
        arraySize+=INCREMENT_ARRAY_SIZE_COEFFICIENT;
        studentList=newStudentList;
        appendMessageData(studentList,studentScoreList,elementSize, payload);
    }
    elementSize++;
}

void deleteMessage(int subscript){
    if(watcherSizeDelete(arraySize,elementSize)){
        deleteMessageData(studentList, subscript, elementSize);
    } else{
        Student *newStudentList= reverseDecrementArraySize(arraySize);
        deleteMessageData(studentList, subscript, elementSize);
        copy(studentList,elementSize,newStudentList);
        arraySize-=DECREMENT_ARRAY_SIZE_COEFFICIENT;
        studentList=newStudentList;
    }
    elementSize--;
}

void replaceMessage(int subscript){
    replaceData(studentList, subscript);
}

void appendScore(StudentScore payload,int subscript){
    appendScoreData(studentScoreList,subscript,payload);
}

void deleteScore(int subscript){
    deleteScoreData(studentScoreList,subscript);
}

void replaceScore(int subscript){
    replaceScoreData(studentScoreList,subscript);
}

void doubleShift(char *newClassname,int subscript){
    exchangeClass(studentList,newClassname,subscript);
}

void showAllStudents(){
    printf("学号\t姓名\t班级\t身份证号\t年龄\t地址\t邮箱\t语文\t数学\t英语\t体育\n");
    for (int i = 0; i < elementSize; ++i) {
        Student student=studentList[i];
        StudentScore studentScore=studentScoreList[i];
            //printf("%s\t%s\t%s\t%s\t%d\t%s\t%s\n",student.id,student.name,student.classname,student.uid,student.age,student.address,student.email);
            printf("%s\t%s\t%s\t%s\t%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",student.id,student.name,student.classname,student.uid,student.age,student.address,student.email,studentScore.Chinese,studentScore.Math,studentScore.English,studentScore.Sport);

    }
}
