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
    void MoveForward() ;

    // 更新朝向
    void TurnLeft();
    void TurnRight() ;

public:
    // 构造函数，初始化位置和朝向
    Executor() : pos({0,0,'N'}) {}

    void Initialize(int initX, int initY, char initHeading) ;

    // 执行指令
    void ExecuteCommands(const string& commands);

    // 获取当前位置和朝向
    void GetStatus(int& currentX, int& currentY, char& currentHeading)const;
    
    void GetPos(Position& currentPos)const;
};


Position test(int x,int y,char heading,const string& commands);