#include "Executor.h"
// Move方法：根据当前朝向和状态逐步移动
     void PoseHandler::Move() {
        // 单次移动一格，考虑倒车状态
        int step = pos.reverse ? -1 : 1;
        switch (pos.heading) {
            case 'N': pos.y += step; break;
            case 'S': pos.y -= step; break;
            case 'E': pos.x += step; break;
            case 'W': pos.x -= step; break;
        }
    }

// MoveSteps方法：处理多步移动逻辑
    void PoseHandler::MoveSteps() {
        int moves = pos.fast ? 2 : 1; // 加速状态下移动两次
        for (int i = 0; i < moves; ++i) {
            Move(); // 调用Move实现逐格移动
        }
    }

// 右转方法：更新朝向，fast状态下移动一次
    void PoseHandler::TurnRight() {
        if (pos.fast) Move(); //fast状态下移动一次
        if(pos.reverse)
        pos.heading = "ESWN"[(GetHeadingIndex() + 3) % 4]; // 倒车则左转
        else pos.heading = "ESWN"[(GetHeadingIndex() + 1) % 4]; //计算右转后的新朝向
    }

// 左转方法：更新朝向，fast状态下移动一次
    void PoseHandler::TurnLeft() {
        if (pos.fast) Move(); // fast状态下移动一次
        if(pos.reverse)
        pos.heading = "ESWN"[(GetHeadingIndex() + 1) % 4]; //倒车则右转
        else pos.heading = "ESWN"[(GetHeadingIndex() + 3) % 4]; // 计算左转后的新朝向
    }


// 获取当前状态
    void PoseHandler::GetPos(Position& currentpos) const {
        currentpos=pos;
    }

// 执行一系列指令，使用表驱动方式提高可扩展性
    void Executor::ExecuteCommands(const string& commands) {
        if(vehicle)
        {
            vehicle->ExecuteCommands(handler,commands);
        }
        // 定义指令字符与对应指令处理器的映射表
        else
        {static const unordered_map<char, function<void(PoseHandler&)>> commandMap = {
            {'M', MoveCommand()},       // 移动
            {'L', TurnLeftCommand()},   // 左转
            {'R', TurnRightCommand()},  // 右转
            {'F', FastCommand()},       // 加速切换
            {'B', ReverseCommand()},    // 倒车切换
        };

        // 遍历指令字符串，逐一执行指令
        for (char cmd : commands) {
            auto it = commandMap.find(cmd); // 在映射表中查找指令
            if (it != commandMap.end()) {
                it->second(handler); // 执行对应指令
            }
        }
        }
    }
//对跑车执行一系列指令
    void SportsCar::ExecuteCommands(PoseHandler& handler,const string& commands)const{
          // 定义指令字符与对应指令处理器的映射表
        static const unordered_map<char,function<void(PoseHandler&)>> commandMap = {
        {'M', [](PoseHandler& handler) { handler.Move(); handler.Move(); }}, // 前进两格
        {'L', [](PoseHandler& handler) { handler.TurnLeft(); handler.Move(); }}, // 左转后前进一步
        {'R', [](PoseHandler& handler) { handler.TurnRight(); handler.Move(); }} // 右转后前进一步
        };
        // 遍历指令字符串，逐一执行指令
        for (char cmd : commands) {
            auto it = commandMap.find(cmd); // 在映射表中查找指令
            if (it != commandMap.end()) {
                it->second(handler); // 执行对应指令
            }
        }
    }
//对巴士执行一系列指令
    void Bus::ExecuteCommands(PoseHandler& handler,const string& commands)const{
          // 定义指令字符与对应指令处理器的映射表
        static const unordered_map<char, function<void(PoseHandler&)>> commandMap =  {
        {'M', [](PoseHandler& handler) { handler.Move(); }}, // 前进一步
        {'L', [](PoseHandler& handler) { handler.Move(); handler.TurnLeft(); }}, // 先前进一步再左转
        {'R', [](PoseHandler& handler) { handler.Move(); handler.TurnRight(); }} // 先前进一步再右转
    };
        // 遍历指令字符串，逐一执行指令
        for (char cmd : commands) {
            auto it = commandMap.find(cmd); // 在映射表中查找指令
            if (it != commandMap.end()) {
                it->second(handler); // 执行对应指令
            }
        }
    }
    Position test(int x, int y, char heading,const char vehicle,const string& commands) {
    Position pos0{x,y,heading,false,false};
    switch(vehicle){
    case 'S':{SportsCar s;Executor executor(pos0,&s);executor.ExecuteCommands(commands);
    Position pos; executor.GetStatus(pos); return pos;}
    case 'B':{Bus b;Executor executor(pos0,&b);executor.ExecuteCommands(commands);
    Position pos; executor.GetStatus(pos); return pos;}
    default :{Executor executor(pos0);executor.ExecuteCommands(commands);
    Position pos; executor.GetStatus(pos); return pos;}
    }    
    return pos0;
    }
