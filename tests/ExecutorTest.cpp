#include <gtest/gtest.h>

#include "Executor.h"

TEST(ExecutorTest, test_case1)
{  
    Position target;
    target={3,2,'E'};
    ASSERT_EQ(target,(test(3,2,'E',"")));
}

TEST(ExecutorTest, test_case2)
{  
    Position target;
    target={0,0,'W'};
    ASSERT_EQ(target,(test(0,0,'N',"LLLLL")));
}
TEST(ExecutorTest, test_case3)
{  
    Position target;
    target={0,3,'N'};
    ASSERT_EQ(target,(test(0,0,'N',"MMM")));
}
TEST(ExecutorTest, test_case4)
{  
    Position target;
    target={6,2,'E'};
    ASSERT_EQ(target,(test(5,0,'E',"MLMMR")));
}
