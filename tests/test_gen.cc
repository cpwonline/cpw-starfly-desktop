#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "cpw_notifications.h"

//-----------------------------------------------------------------------------

class TestGen : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestGen);
	CPPUNIT_TEST(testViewNotification_);
	CPPUNIT_TEST(testViewVersionSoftware_);
	CPPUNIT_TEST_SUITE_END();

	public:
		TestGen();
		void setUp(void);
		void tearDown(void);

	protected:
		void testViewNotification_(void);
		void testViewVersionSoftware_(void);

	private:
		CPWNotifications *mTestObj;
};

//-----------------------------------------------------------------------------

TestGen::TestGen(){}

void TestGen::testViewNotification_(void)
{
	mTestObj->ReceiveData_((char*)"app.id.com", (char*)"nombre", (char*)"cuerpo", (char*)"battery-low");
	CPPUNIT_ASSERT(true == mTestObj->PrepareNotification_());
	mTestObj->AddThemedIcon_();
	mTestObj->ShowNotification_();
}

void TestGen::testViewVersionSoftware_(void)
{
	CPPUNIT_ASSERT(0 == cpw_notifications_VERSION_MAJOR);
	CPPUNIT_ASSERT(0 == cpw_notifications_VERSION_MINOR);
	CPPUNIT_ASSERT(1 == cpw_notifications_VERSION_PATCH);
}

void TestGen::setUp(void)
{
    mTestObj = new CPWNotifications();
}

void TestGen::tearDown(void)
{
    delete mTestObj;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION(TestGen);

int main(int argc, char* argv[])
{
    CPPUNIT_NS::TestResult testresult;

    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    testrunner.run(testresult);

    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    return collectedresults.wasSuccessful() ? 0 : 1;
}
