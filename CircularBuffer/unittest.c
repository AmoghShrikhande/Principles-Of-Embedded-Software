#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include <CUnit/Automated.h>
#include <CUnit/CUnit.h>
#include "circular_buffer.h"
#define LENGTH 20

int init_suite1(void);
int clean_suite1(void);
int register_test_suite(void);
void cbuff_config_test(void);
void cbuff_insert_test(void);
void cbuff_delete_test(void);
void cbuff_remove_test(void);


//Global Variables
cbuff_t *test_ptr;

int init_suite1(void)
{
	test_ptr = (cbuff_t *)malloc(sizeof(int8_t)*LENGTH);	
	return 0;  
}

int clean_suite1(void)
{
	free(test_ptr);
    	return 0;
}


void cbuff_config_test(void)
{
	CU_ASSERT_EQUAL(cbuff_config(test_ptr,LENGTH),CONFIG_SUCCESS);
}

void cbuff_insert_test(void)
{
	//Try to Delete Before entering character
	CU_ASSERT_EQUAL(cbuff_delete(test_ptr),CBUFF_EMPTY);
	
	//Add 5 characters in the circular buffer
	CU_ASSERT_EQUAL(cbuff_insert(test_ptr,'a'),CBUFF_ADD_SUCCESS);
	CU_ASSERT_EQUAL(cbuff_insert(test_ptr,'m'),CBUFF_ADD_SUCCESS);
	CU_ASSERT_EQUAL(cbuff_insert(test_ptr,'o'),CBUFF_ADD_SUCCESS);
	CU_ASSERT_EQUAL(cbuff_insert(test_ptr,'g'),CBUFF_ADD_SUCCESS);
	CU_ASSERT_EQUAL(cbuff_insert(test_ptr,'h'),CBUFF_ADD_SUCCESS);
}

void cbuff_delete_test(void)
{
	for(int i=0;i<3;i++){
		CU_ASSERT_EQUAL(cbuff_delete(test_ptr),CBUFF_DELETE_SUCCESS);
	}
}



int main()
{
	//Initialization of cunit test registry
	if(CU_initialize_registry() != CUE_SUCCESS)
	{
		return CU_get_error();
	}

	//Add test suite to Cunit test registry
	if(register_test_suite() == -1)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	//basic interface to run test cases
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();


	CU_set_output_filename("CircularBuffer_UnitTest");
	CU_automated_run_tests();

	//Clean up registry
	CU_cleanup_registry();
	return CU_get_error();
}


int register_test_suite()
{
	CU_pSuite pSuite = NULL;

	//Add suite to registry
	pSuite = CU_add_suite("Circular Buffer CUnit Test",init_suite1,clean_suite1);

	if(pSuite == NULL)
	{
		return -1;
	}

	if((CU_add_test(pSuite,"Configure Circular Buffer",cbuff_config_test)== NULL) || (CU_add_test(pSuite,"Add Character in Circular Buffer",cbuff_insert_test)== NULL) || (CU_add_test(pSuite,"Delete Character from Circular Buffer",cbuff_delete_test)== NULL))
	{
		return -1;
	}

	return 0;
}
