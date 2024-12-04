#include "Executor.h"

// 前进指令
void MoveCommand::DoOperate(int& x, int& y, char& heading, bool& fast){
        int steps = fast ? 2 : 1; // 加速状态前进2格
        for (int i = 0; i < steps; ++i) {
            switch (heading) {
                case 'N': y += 1; break;
                case 'S': y -= 1; break;
                case 'E': x += 1; break;
                case 'W': x -= 1; break;
            }
        }
    }

// 左转指令
void TurnLeftCommand::DoOperate(int& x, int& y, char& heading, bool& fast){
        if (fast) { // 加速状态，先前进1格
            MoveCommand move;
            bool unfast=!fast;
            move.DoOperate(x, y, heading,unfast);
        }
        switch (heading) {
            case 'N': heading = 'W'; break;
            case 'S': heading = 'E'; break;
            case 'E': heading = 'N'; break;
            case 'W': heading = 'S'; break;
        }
    }

// 右转指令
void TurnRightCommand::DoOperate(int& x, int& y, char& heading, bool& fast){
        if (fast) { // 加速状态，先前进1格
            MoveCommand move;
            bool unfast=!fast;
            move.DoOperate(x, y, heading,unfast);
        }
        switch (heading) {
            case 'N': heading = 'E'; break;
            case 'S': heading = 'W'; break;
            case 'E': heading = 'S'; break;
            case 'W': heading = 'N'; break;
        }
    }
//改变加速状态
void FastCommand::DoOperate(int& x, int& y, char& heading, bool& fast){
        fast=!fast;
}

    // 批量执行指令
    void Executor::ExecuteCommands(const string& commands){
        for (char command : commands) {
            switch (command) {
                case 'M': moveCommand.DoOperate(pos.x,pos.y,pos.heading,pos.fast);break;
                case 'L': turnLeftCommand.DoOperate(pos.x,pos.y,pos.heading,pos.fast);break;
                case 'R': turnRightCommand.DoOperate(pos.x,pos.y,pos.heading,pos.fast);break;
                case 'F': fastCommand.DoOperate(pos.x,pos.y,pos.heading,pos.fast);break;
            }
    }
    }

    //初始化位置和朝向
    void Executor::Initialize(int initX, int initY, char initHeading) {
        pos.x = initX;
        pos.y = initY;
        pos.heading = initHeading;
    }

    // 获取当前位置和朝向
    void Executor::GetStatus(int& currentX, int& currentY, char& currentHeading) const {
        currentX = pos.x;
        currentY = pos.y;
        currentHeading = pos.heading;
    }

    void Executor::GetPos(Position& currentPos)const{
        currentPos=pos;
    }

     //查询加速状态
    bool Executor::IsFast(){
        return pos.fast;
    }

    Position test(int x,int y,char heading,const string& commands){
    Executor car;
    Position pos;
    car.Initialize(x,y,heading);
    car.ExecuteCommands(commands);
    car.GetPos(pos);
    return pos;
}