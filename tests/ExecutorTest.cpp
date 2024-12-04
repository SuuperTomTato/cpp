#include <gtest/gtest.h>

#include "Executor.h"

TEST(ExecutorTest, test_case1)
{  
    Position target;
    target={0,0,'N',true};
    ASSERT_EQ(target,(test(0,0,'N',"F")));
}

TEST(ExecutorTest, test_case2)
{  
    Position target;
    target={0,3,'N',false};
    ASSERT_EQ(target,(test(0,0,'N',"FMFM")));
}

TEST(ExecutorTest, test_case3)
{  
    Position target;
    target={0,1,'E',false};
    ASSERT_EQ(target,(test(0,0,'N',"FRF")));
}

TEST(ExecutorTest, test_case4)
{  
    Position target;
    target={0,1,'W',false};
    ASSERT_EQ(target,(test(0,0,'N',"FLF")));
}
TEST(ExecutorTest, test_case5)
{  
    Position target;
    target={-8,7,'W',false};
    ASSERT_EQ(target,(test(0,0,'N',"FMMMLMMMMF")));
}
