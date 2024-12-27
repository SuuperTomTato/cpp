#include <gtest/gtest.h>

#include "Executor.h"

TEST(ExecutorTest, test_case1)
{  
    Position target;
    target={0,2,'N',false,false};
    ASSERT_EQ(target,(test(0,0,'N','S',"M")));
}

TEST(ExecutorTest, test_case2)
{  
    Position target;
    target={-1,0,'W',false,false};
    ASSERT_EQ(target,(test(0,0,'N','S',"L")));
}

TEST(ExecutorTest, test_case3)
{  
    Position target;
    target={7,3,'N',false,false};
    ASSERT_EQ(target,(test(0,0,'N','S',"MRMMML")));
}

TEST(ExecutorTest, test_case4)
{  
    Position target;
    target={0,1,'N',false,false};
    ASSERT_EQ(target,(test(0,0,'N','B',"M")));
}
TEST(ExecutorTest, test_case5)
{  
    Position target;
    target={0,1,'E',false,false};
    ASSERT_EQ(target,(test(0,0,'N','B',"R")));
}
TEST(ExecutorTest, test_case6)
{  
    Position target;
    target={4,5,'N',false,false};
    ASSERT_EQ(target,(test(0,1,'N','B',"MMMRMMML")));
}