#include <gtest/gtest.h>

#include "Executor.h"

TEST(ExecutorTest, test_case1)
{  
    Position target;
    target={0,0,'N',false,true};
    ASSERT_EQ(target,(test(0,0,'N',"BBB")));
}

TEST(ExecutorTest, test_case2)
{  
    Position target;
    target={0,-1,'N',false,true};
    ASSERT_EQ(target,(test(0,0,'N',"BM")));
}

TEST(ExecutorTest, test_case3)
{  
    Position target;
    target={0,-2,'N',true,true};
    ASSERT_EQ(target,(test(0,0,'N',"FBM")));
}

TEST(ExecutorTest, test_case4)
{  
    Position target;
    target={0,0,'E',false,true};
    ASSERT_EQ(target,(test(0,0,'N',"BL")));
}
TEST(ExecutorTest, test_case5)
{  
    Position target;
    target={0,-1,'W',true,true};
    ASSERT_EQ(target,(test(0,0,'N',"BFR")));
}
TEST(ExecutorTest, test_case6)
{  
    Position target;
    target={4,-5,'N',false,false};
    ASSERT_EQ(target,(test(2,3,'W',"MBFMLMMMMBF")));
}