#include "Executor.h"

// 根据朝向和指令更新位置
    void Executor::MoveForward() {
        switch (pos.heading) {
            case 'N': pos.y += 1; break;
            case 'S': pos.y -= 1; break;
            case 'E': pos.x += 1; break;
            case 'W': pos.x -= 1; break;
        }
    }

 // 更新朝向
    void Executor::TurnLeft() {
        switch (pos.heading) {
            case 'N': pos.heading = 'W'; break;
            case 'W': pos.heading = 'S'; break;
            case 'S': pos.heading = 'E'; break;
            case 'E': pos.heading = 'N'; break;
        }
    }

    void Executor::TurnRight() {
        switch (pos.heading) {
            case 'N': pos.heading = 'E'; break;
            case 'E': pos.heading = 'S'; break;
            case 'S': pos.heading = 'W'; break;
            case 'W': pos.heading = 'N'; break;
        }
    }

    void Executor::Initialize(int initX, int initY, char initHeading) {
        pos.x = initX;
        pos.y = initY;
        pos.heading = initHeading;
    }

    // 执行指令
    void Executor::ExecuteCommands(const string& commands) {
        for (char command : commands) {
            switch (command) {
                case 'M': MoveForward(); break;
                case 'L': TurnLeft(); break;
                case 'R': TurnRight(); break;
            }
        }
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



    Position test(int x,int y,char heading,const string& commands){
    Executor car;
    Position pos;
    car.Initialize(x,y,heading);
    car.ExecuteCommands(commands);
    car.GetPos(pos);
    return pos;
}