/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2021
 *
 * @file      google_test_runner.cpp
 * @authors   Jim Daehn <jdaehn@missouristate.edu>
 * @brief     Google Test implementation template.
 */

#include "csc232.h"
#include "gtest/gtest.h"

/**
 * @brief Namespace to encapsulate course specific macros, declarations and definitions.
 */
namespace csc232
{
    static int possiblePoints { 0 };
    static int earnedPoints { 0 };
    static const int MAX_CORRECTNESS_PTS { 3 };

    /**
     * @brief Base test fixture that sets up grading for this assignment.
     */
    class CSC232BaseTestFixture : public ::testing::Test
    {
    public:
        CSC232BaseTestFixture() : buffer{std::stringstream{}}, sbuf{nullptr} {
            // Intentionally empty; initialization done via initializer list
        }

    protected:
        void SetUp ( ) override
        {
            ::testing::FLAGS_gtest_death_test_style = "threadsafe";
            // Redirect cout to our stringstream buffer or any other ostream
            sbuf = std::cout.rdbuf( );
            std::cout.rdbuf( buffer.rdbuf( ));

            AdditionalSetup( );

            possiblePoints += 1;
        }

        void TearDown ( ) override
        {
            // When done redirect cout to its old self
            std::cout.rdbuf( sbuf );
            sbuf = nullptr;

            AdditionalTearDown( );

            if ( !HasFailure( ))
            {
                earnedPoints += 1;
            }
        }

        virtual void AdditionalSetup ( )
        {
            /* template method for any customized additional setup */
        }

        virtual void AdditionalTearDown ( )
        {
            /* template method for any customized additional setup */
        }

        // Reusable objects for each unit test in this test fixture and any of its children
        std::stringstream buffer;
        std::streambuf* sbuf;
        /*
         * With the above in place, you can now have tests on output statements 
         * like this:
         * 
         * <some function call or executable that inserts info into output stream...>
         * const std::string expected{ "1/1/1902\n" }; // what you expect to have been inserted
         * const std::string actual{ buffer.str( ) };  // what was actually inserted
         * EXPECT_EQ( expected, actual );
         */
    };

#if !TEST_TASK01
    TEST_F( CSC232BaseTestFixture, DISABLED_TestExpectedOutput )
    {
        std::cout << "Google Test" << std::endl;
        const std::string expected { "Google Test\n" };
        const std::string actual { buffer.str( ) };
        EXPECT_STREQ( expected.c_str( ), actual.c_str( ) );
    }

    // Extend the base test fixture as needed for various components under test...
    class DISABLED_CSC232ChildClassTestFixture : public CSC232BaseTestFixture
    {
    protected:
        // Reusable objects for each unit test in this test fixture
    };

    TEST_F( DISABLED_CSC232ChildClassTestFixture, ValidateFailedAssertionTest )
    {
        EXPECT_DEATH( {
            assert( false ); // some line(s) of code that will cause a failed assertion
        }, ".*failed.*" );
    }
#endif

#if TEST_TASK01
    class Task01TestFixture : public CSC232BaseTestFixture
    {
    public:
        Task01TestFixture() = default;
    };
#endif

#if TEST_TASK02
    class Task02TestFixture : public CSC232BaseTestFixture
    {
    public:
        Task02TestFixture() = default;
    };
#endif

#if TEST_TASK03
    class Task03TestFixture : public CSC232BaseTestFixture
    {
    public:
        Task03TestFixture() = default;
    };
#endif

} // end namespace

int main ( int argc, char** argv )
{
    ::testing::InitGoogleTest( &argc, argv );
    int result { RUN_ALL_TESTS( ) };
    std::cout << std::fixed << std::setprecision( 2 );
    std::cout << "\n\n";
    std::cout << std::left << std::setw( 21 ) << "Earned Points:"
              << std::right << std::setw( 5 ) << static_cast<double>(csc232::earnedPoints) << std::endl;
    std::cout << std::left << std::setw( 21 ) << "Possible Points:"
              << std::right << std::setw( 5 ) << static_cast<double>(csc232::possiblePoints) << std::endl;
    double percentCorrect { static_cast<double>(csc232::earnedPoints) / csc232::possiblePoints };
    double correctnessPoints { csc232::possiblePoints != 0 ? percentCorrect * csc232::MAX_CORRECTNESS_PTS
                                                           : 0 };
    std::cout << std::left << std::setw( 21 ) << "Correctness Points:"
              << std::right << std::setw( 5 ) << correctnessPoints << std::endl;
    return result;
}
