#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Position
{
    int x;
    int y;
    char heading;
    bool fast;
    bool operator==(const Position& other) const {
        return ((x==other.x)&&(y==other.y)&&(heading==other.heading)&&(fast==other.fast));
    }
};


// 定义虚基类 ICommand
class ICommand {
public:
    virtual void DoOperate(int& x, int& y, char& heading, bool& fast) = 0;
    virtual ~ICommand() {}
};

// 前进指令
class MoveCommand : public ICommand {
public:
    void DoOperate(int& x, int& y, char& heading, bool& fast) override ;
};

// 左转指令
class TurnLeftCommand : public ICommand {
public:
    void DoOperate(int& x, int& y, char& heading, bool& fast) override ;
};

// 右转指令
class TurnRightCommand : public ICommand {
public:
    void DoOperate(int& x, int& y, char& heading, bool& fast) override ;
};
//加速状态改变指令
class FastCommand:public ICommand{
public:
    void DoOperate(int& x, int& y, char& heading, bool& fast)override;
};
// Executor 组件类
class Executor {
private:
    Position pos;
    MoveCommand moveCommand;
    TurnLeftCommand turnLeftCommand;
    TurnRightCommand turnRightCommand;
    FastCommand fastCommand;

public:
    // 构造函数，初始化位置和朝向
    Executor() : pos({0,0,'N',false}) {}

    void Initialize(int initX, int initY, char initHeading) ;

   // 批量执行指令
    void ExecuteCommands(const string& commands);

    // 获取当前位置和朝向
    void GetStatus(int& currentX, int& currentY, char& currentHeading)const;
    
    void GetPos(Position& currentPos)const;

    //查询加速状态
    bool IsFast();

};


Position test(int x,int y,char heading,const string& commands);