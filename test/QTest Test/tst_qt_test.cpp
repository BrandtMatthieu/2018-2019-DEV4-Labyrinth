#include <QtTest>

// add necessary includes here

class qt_test : public QObject {
		Q_OBJECT

	public:
		qt_test();
		~qt_test();

	private

		slots:
				void

		test_case1();

};

qt_test::qt_test() {

}

qt_test::~qt_test() {

}

void qt_test::test_case1() {

}

QTEST_APPLESS_MAIN(qt_test)

#include "tst_qt_test.moc"
