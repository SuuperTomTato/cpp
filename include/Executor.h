#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Position
{
    int x;
    int y;
    char heading;
    bool operator==(const Position& other) const {
        return ((x==other.x)&&(y==other.y)&&(heading==other.heading));
    }
};
// Executor 组件类
class Executor {
private:
    Position pos;
    void moveForward() ;

    // 更新朝向
    void turnLeft();
    void turnRight() ;

public:
    // 构造函数，初始化位置和朝向
    Executor() : pos({0,0,'N'}) {}

    void initialize(int initX, int initY, char initHeading) ;

    // 执行指令
    void executeCommands(const string& commands);

    // 获取当前位置和朝向
    void getStatus(int& currentX, int& currentY, char& currentHeading)const;
    
    void getPos(Position& currentPos)const;
};


Position test(int x,int y,char heading,const string& commands);