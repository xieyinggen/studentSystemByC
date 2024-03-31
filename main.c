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
    printf("****��ӭʹ��ѧ������ϵͳ****\n");
    int userAction;
    while (true){
        printf("****����������ʵ�еĲ���****\n");
        printf("****0��ʾ�˳�ϵͳ\t1��ʾ���ѧ������Ϣ\t2��ʾɾ��ѧ������Ϣ\t3��ʾ�޸�ѧ������Ϣ\t4��ʾ���ѧ���ĳɼ�\t5��ʾɾ��ѧ���ĳɼ�\t6��ʾ�޸�ѧ���ĳɼ�\t7��ʾ�ϰ�\t8��ʾ�鿴ѧ���ĳɼ�����Ϣ: ");
        scanf("%d",&userAction);
        switch (userAction) {
            case END_ACTION:{
                printf("��л����ʹ��,�������ʹ�ù���������ʲô����,����ϵ�ֻ���131********,�����ڴ���Ϊ�����ṩ����Ľ��顣");
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
                printf("������ѧ��������: ");
                scanf("%s",name);
                student->name=name;
                printf("������ѧ����ѧ��: ");
                scanf("%s",id);
                student->id=id;
                printf("������ѧ���İ༶: ");
                scanf("%s",classname);
                student->classname=classname;
                printf("������ѧ�������֤��: ");
                scanf("%s",uid);
                student->uid=uid;
                printf("���ʻ����������ѧ����ȫ����Ϣ��? ��Ҫ�������0��������,����Ҫ������0: ");
                scanf("%d",&userChoice);
                if(userChoice){
                    printf("������ѧ��������: ");
                    scanf("%d",&age);
                    student->age=age;
                    printf("������ѧ���ĵ�ַ: ");
                    scanf("%s",address);
                    student->address=address;
                    printf("������ѧ��������: ");
                    scanf("%s",email);
                    student->email=email;
                } else{
                    student->age=0;
                    student->address="��";
                    student->email="��";
                }
                appendMessage(*student);
                break;
            }
            case DECREMENT_MESSAGE_ACTION:{
                printf("�����뱻ɾ��ѧ����ѧ��: ");
                char *id;
                id=(char *) malloc(sizeof (char)*DEFINE_SPACE);
                scanf("%s",id);
                for (int i = 0; i < elementSize; ++i) {
                    if(strcmp(studentList[i].id,id)==0){
                        deleteMessage(i);
                        break;
                    } else if(i==elementSize-1){
                        printf("�������ѧ�Ų�����\n");
                    }
                }
                break;
            }
            case REPLACE_MESSAGE_ACTION:{
                printf("��������Ҫ�޸���Ϣ��ѧ����ѧ��(������Ҫ�޸ĵ���ѧ����ѧ��,��ͨ���鿴ѧ����Ϣ��ȡ��ѧ����ѧ��): ");
                char *id;
                id=(char *) malloc(sizeof (char)*DEFINE_SPACE);
                scanf("%s",id);
                for (int i = 0; i < elementSize; ++i) {
                    if(strcmp(studentList[i].id,id)==0){
                        replaceMessage(i);
                        break;
                    } else if(i==elementSize-1){
                        printf("�������ѧ�Ų�����\n");
                    }
                }
                break;
            }
            case INCREMENT_SCORE_ACTION:{
                float Chinese,Math,English,Sport;
                char *id;
                id=(char *) malloc(sizeof (char)*DEFINE_SPACE);
                StudentScore *student=(StudentScore *) malloc(sizeof (StudentScore));
                printf("�����뱻��ӳɼ�ѧ����ѧ��: ");
                scanf("%s",id);
                printf("���������ĳɼ�: ");
                for (int i = 0; ; ++i) {
                    scanf("%f",&Chinese);
                    if(Chinese<=SCORE_MAIN_SUBJECT_MAX&&Chinese>=SCORE_MAIN_SUBJECT_MIN){
                        break;
                    } else{
                        printf("����ɼ����ܳ���0����100�������,����������: ");
                    }
                }
                student->Chinese=Chinese;
                printf("��������ѧ�ɼ�: ");
                for (int i = 0; ; ++i) {
                    scanf("%f",&Math);
                    if(Math<=SCORE_MAIN_SUBJECT_MAX&&Math>=SCORE_MAIN_SUBJECT_MIN){
                        break;
                    } else{
                        printf("����ɼ����ܳ���0����100�������,����������: ");
                    }
                }
                student->Math=Math;
                printf("������Ӣ��ɼ�: ");
                for (int i = 0; ; ++i) {
                    scanf("%f",&English);
                    if(English<=SCORE_MAIN_SUBJECT_MAX&&English>=SCORE_MAIN_SUBJECT_MIN){
                        break;
                    } else{
                        printf("����ɼ����ܳ���0����100�������,����������: ");
                    }
                }
                student->English=English;
                printf("�����������ɼ�: ");
                for (int i = 0; ; ++i) {
                    scanf("%f",&Sport);
                    if(Sport<=SCORE_PE_MAX&&Sport>=SCORE_PE_MIN){
                        break;
                    } else{
                        printf("����ɼ����ܳ���0����30�������,����������: ");
                    }
                }
                student->Sport=Sport;
                for (int i = 0; i < elementSize; ++i) {
                    if(strcmp(studentList[i].id,id)==0){
                        appendScore(*student,i);
                        break;
                    } else if(i==elementSize-1){
                        printf("�������ѧ�Ų�����\n");
                    }
                }
                break;
            }
            case DECREMENT_SCORE_ACTION:{
                char *id;
                id=(char *) malloc(sizeof (char)*DEFINE_SPACE);
                printf("�����뱻ɾ���ɼ���ѧ����ѧ��");
                scanf("%s",id);
                for (int i = 0; i < elementSize; ++i) {
                    if(strcmp(studentList[i].id,id)==0){
                        deleteScore(i);
                        break;
                    } else if(i==elementSize-1){
                        printf("�������ѧ�Ų�����: ");
                    }
                }
                break;
            }
            case REPLACE_SCORE_ACTION:{
                char *id;
                id=(char *) malloc(sizeof (char)*DEFINE_SPACE);
                printf("��������Ҫ�޸ĳɼ���ѧ����ѧ��");
                scanf("%s",id);
                for (int i = 0; i < elementSize; ++i) {
                    if(strcmp(studentList[i].id,id)==0){
                        replaceScore(i);
                        break;
                    } else if(i==elementSize-1){
                        printf("�������ѧ�Ų�����: ");
                    }
                }
                break;
            }
            case DOUBLE_SHIFT_ACTION: {
                char *oldClassname,*newClassname;
                int state=0;
                oldClassname=(char *) malloc(sizeof (char) * DEFINE_SPACE);
                newClassname=(char *) malloc(sizeof (char) * DEFINE_SPACE);
                printf("������Ҫ�ϲ����İ༶: ");
                scanf("%s",newClassname);
                printf("�����뱻�ϲ��İ༶: ");
                scanf("%s",oldClassname);
                for (int i = 0; i < elementSize; ++i) {
                    if(strcmp(studentList[i].classname,oldClassname)==0){
                        doubleShift(newClassname,i);
                        state=1;
                        continue;
                    } else if(i==elementSize-1&&state==0){
                        printf("������İ༶������: ");
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
    printf("ѧ��\t����\t�༶\t���֤��\t����\t��ַ\t����\t����\t��ѧ\tӢ��\t����\n");
    for (int i = 0; i < elementSize; ++i) {
        Student student=studentList[i];
        StudentScore studentScore=studentScoreList[i];
            //printf("%s\t%s\t%s\t%s\t%d\t%s\t%s\n",student.id,student.name,student.classname,student.uid,student.age,student.address,student.email);
            printf("%s\t%s\t%s\t%s\t%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",student.id,student.name,student.classname,student.uid,student.age,student.address,student.email,studentScore.Chinese,studentScore.Math,studentScore.English,studentScore.Sport);

    }
}
