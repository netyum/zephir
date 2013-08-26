
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Test_Constants) {

	ZEPHIR_REGISTER_CLASS(Test, Constants, constants, test_constants_method_entry, 0);

	zend_declare_class_constant_null(test_constants_ce, SL("C1") TSRMLS_CC);
	zend_declare_class_constant_bool(test_constants_ce, SL("C2"), 0 TSRMLS_CC);
	zend_declare_class_constant_bool(test_constants_ce, SL("C3"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(test_constants_ce, SL("C4"), 10 TSRMLS_CC);
	zend_declare_class_constant_double(test_constants_ce, SL("C5"), 10.25 TSRMLS_CC);
	zend_declare_class_constant_string(test_constants_ce, SL("C6"), "test" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Test_Constants, testReadConstant) {

	RETURN_LONG(3);


}

PHP_METHOD(Test_Constants, testReadClassConstant) {

	phalcon_get_class_constant(return_value, test_constants_ce, SS("C1") TSRMLS_CC);
	return;


}
