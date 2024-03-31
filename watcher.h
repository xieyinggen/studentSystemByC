//
// Created by xiada on 2024/3/30.
//

#ifndef UNTITLED16_WATCHER_H
#define UNTITLED16_WATCHER_H

bool watcherSizeAppend(int arraySize,int elementSize){
    if(arraySize<=elementSize){
        return false;
    } else{
        return true;
    }
}

bool watcherSizeDelete(int arraySize,int elementSize){
    if(arraySize-elementSize>=10){
        return false;
    } else{
        return true;
    }
}


#endif //UNTITLED16_WATCHER_H
