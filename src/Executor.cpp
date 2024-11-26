#include "Executor.h"

// 根据朝向和指令更新位置
    void Executor::moveForward() {
        switch (pos.heading) {
            case 'N': pos.y += 1; break;
            case 'S': pos.y -= 1; break;
            case 'E': pos.x += 1; break;
            case 'W': pos.x -= 1; break;
        }
    }

 // 更新朝向
    void Executor::turnLeft() {
        switch (pos.heading) {
            case 'N': pos.heading = 'W'; break;
            case 'W': pos.heading = 'S'; break;
            case 'S': pos.heading = 'E'; break;
            case 'E': pos.heading = 'N'; break;
        }
    }

    void Executor::turnRight() {
        switch (pos.heading) {
            case 'N': pos.heading = 'E'; break;
            case 'E': pos.heading = 'S'; break;
            case 'S': pos.heading = 'W'; break;
            case 'W': pos.heading = 'N'; break;
        }
    }

    void Executor::initialize(int initX, int initY, char initHeading) {
        pos.x = initX;
        pos.y = initY;
        pos.heading = initHeading;
    }

    // 执行指令
    void Executor::executeCommands(const string& commands) {
        for (char command : commands) {
            switch (command) {
                case 'M': moveForward(); break;
                case 'L': turnLeft(); break;
                case 'R': turnRight(); break;
            }
        }
    }

    // 获取当前位置和朝向
    void Executor::getStatus(int& currentX, int& currentY, char& currentHeading) const {
        currentX = pos.x;
        currentY = pos.y;
        currentHeading = pos.heading;
    }

    void Executor::getPos(Position& currentPos)const{
        currentPos=pos;
    }



    Position test(int x,int y,char heading,const string& commands){
    Executor car;
    Position pos;
    car.initialize(x,y,heading);
    car.executeCommands(commands);
    car.getPos(pos);
    return pos;
}