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
    printf("����������Ҫ�޸�ѧ������Ϣ****1��ʾѧ��\t2��ʾ����\t3��ʾ�༶\t4��ʾ���֤��\t5��ʾ����\t6��ʾ��ַ\t7��ʾ����: ");
    scanf("%d",&userChoice);
    switch (userChoice) {
        case REPLACE_ID:{
            char *id;
            id=(char *) malloc(sizeof (char)*DEFINE_SPACE);
            printf("������ѧ��: ");
            scanf("%s",id);
            array[subscript].id=id;
            break;
        }
        case REPLACE_NAME:{
            char *name;
            name=(char *) malloc(sizeof (char) * DEFINE_SPACE);
            printf("����������: ");
            scanf("%s", name);
            array[subscript].name=name;
            break;
        }
        case REPLACE_CLASSNAME:{
            char *classname;
            classname=(char *) malloc(sizeof (char) * DEFINE_SPACE);
            printf("������༶: ");
            scanf("%s", classname);
            array[subscript].classname=classname;
            break;
        }
        case REPLACE_UID:{
            char *uid;
            uid=(char *) malloc(sizeof (char) * DEFINE_SPACE);
            printf("���������֤��: ");
            scanf("%s", uid);
            array[subscript].uid=uid;
            break;
        }
        case REPLACE_AGE:{
            int age;
            printf("����������: ");
            scanf("%d", &age);
            array[subscript].age=age;
            break;
        }
        case REPLACE_ADDRESS:{
            char *address;
            address=(char *) malloc(sizeof (char) * DEFINE_SPACE);
            printf("�������ַ: ");
            scanf("%s", address);
            array[subscript].address=address;
            break;
        }
        case REPLACE_EMAIL:{
            char *email;
            email=(char *) malloc(sizeof (char) * DEFINE_SPACE);
            printf("����������: ");
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
    printf("��������Ҫɾ����ѧ��****1��ʾ����\t2��ʾ��ѧ\t3��ʾӢ��\t4��ʾ����\t5��ʾȫ��: ");
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
    printf("��������Ҫ�޸ĵ�ѧ��****1��ʾ����\t2��ʾ��ѧ\t3��ʾӢ��\t4��ʾ����\t5��ʾȫ��: ");
    scanf("%d", &userChoice);
    switch (userChoice) {
        case DELETE_CHINESE: {
            float Chinese;
            printf("�������޸ĺ�ĳɼ�: ");
            scanf("%f",&Chinese);
            array[subscript].Chinese = Chinese;
            break;
        }
        case DELETE_MATH: {
            float Math;
            printf("�������޸ĺ�ĳɼ�: ");
            scanf("%f",&Math);
            array[subscript].Math = Math;
            break;
        }
        case DELETE_ENGLISH: {
            float English;
            printf("�������޸ĺ�ĳɼ�: ");
            scanf("%f",&English);
            array[subscript].English = English;
            break;
        }
        case DELETE_SPORT: {
            float Sport;
            printf("�������޸ĺ�ĳɼ�: ");
            scanf("%f",&Sport);
            array[subscript].Sport = Sport;
            break;
        }
        case DELETE_ALL_SUBJECT: {
            float Chinese,Math,English,Sport;
            printf("�������޸ĺ�����ĳɼ�: ");
            scanf("%f",&Chinese);
            array[subscript].Chinese = Chinese;
            printf("�������޸ĺ����ѧ�ɼ�: ");
            scanf("%f",&Math);
            array[subscript].Math = Math;
            printf("�������޸ĺ��Ӣ��ɼ�: ");
            scanf("%f",&English);
            array[subscript].English = English;
            printf("�������޸ĺ�������ɼ�: ");
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