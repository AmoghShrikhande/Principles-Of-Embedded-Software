///*========================================================================
//** ring_test.c
//** Circular buffer testing
//** ECEN5813
//**========================================================================*/
//
///**********************
//******INCLUDES*********
//**********************/
//#include <stdio.h>
//#include <stdlib.h>
//#include <CUnit/Basic.h>
//#include <CUnit/Automated.h>
//#include <CUnit/CUnit.h>
//#include <time.h>
//
//#include "../includes/c_buff.h"
//
//enum STATUS {
//	SUCCESS = 1,
//	FAIL = -1,
//	BUFF_FULL =-2,
//	BUFF_EMPTY =-3
//};
//
//int64_t array_elements[10];
//
//
///*********************************
//******FUCNTION PROTOTYPES*********
//**********************************/
//int init_suite1(void);
//int clean_suite1(void);
//int register_test_suite(void);
//
//int init_suite1(void)
//{
//
//      return 0;
//}
///* The suite cleanup function.
// * Closes the temporary file used by the tests.
// * Returns zero on success, non-zero otherwise.
// */
//int clean_suite1(void)
//{
//    return 0;
//}
//
///**************************************************************************************************************************************/
//
///*Carrying all the basic functionalities without any error checks*/
//void test_suite1() //suite1
//{
//	c_buf *ring;
//	array_elements[0] = 5;
//
//	ring = buffer_init(1,array_elements);
//	CU_ASSERT_NOT_EQUAL(ring,NULL);
//	printf("\n Entered the test suite");
//	//CU_ASSERT_EQUAL(display_buffer(0),SUCCESS);
//
//	//CU_ASSERT_EQUAL(buffer_init(1,array_elements),SUCCESS);
//	//char c;
//
//	CU_ASSERT_EQUAL(add_elements(ring,'a'),SUCCESS);
//	CU_ASSERT_EQUAL(add_elements(ring,'b'),SUCCESS);
//	CU_ASSERT_EQUAL(add_elements(ring,'c'),SUCCESS);
//	CU_ASSERT_EQUAL(add_elements(ring,'d'),SUCCESS);
//	CU_ASSERT_EQUAL(add_elements(ring,'e'),SUCCESS);
//
//	// CU_ASSERT_EQUAL(display_buffer(0),SUCCESS);
//
//	// CU_ASSERT_EQUAL(delete_buffer(0),SUCCESS);
//	// CU_ASSERT_EQUAL(delete_buffer(0),SUCCESS);
//	// CU_ASSERT_EQUAL(delete_buffer(0),SUCCESS);
//	// CU_ASSERT_EQUAL(delete_buffer(0),SUCCESS);
//	// CU_ASSERT_EQUAL(delete_buffer(0),SUCCESS);
//
//	// CU_ASSERT_EQUAL(display_buffer(0),SUCCESS);
//
//}
//
//
///*Conditions for Full Buffe and Empty buffer*/
//// void test_suite2() //suite2
//// {
//// 	ring_t *ring;
//// 	ring= init(12);
//// 	CU_ASSERT_NOT_EQUAL(ring,NULL);
//// 	char c;
//// 	CU_ASSERT_EQUAL(insert(ring,'a'),SUCCESS);
//// 	CU_ASSERT_EQUAL(remove_t(ring,&c),SUCCESS);
//// 	CU_ASSERT_EQUAL(remove_t(ring,&c),BUFF_EMPTY);
//// 	CU_ASSERT_EQUAL(insert(ring,'b'),SUCCESS);
//// 	CU_ASSERT_EQUAL(insert(ring,'c'),SUCCESS);
//// 	CU_ASSERT_EQUAL(insert(ring,'d'),SUCCESS);
//// 	CU_ASSERT_EQUAL(insert(ring,'e'),SUCCESS);
//// 	CU_ASSERT_EQUAL(insert(ring,'f'),SUCCESS);
//// 	CU_ASSERT_EQUAL(insert(ring,'g'),SUCCESS);
//// 	CU_ASSERT_EQUAL(insert(ring,'h'),SUCCESS);
//// 	CU_ASSERT_EQUAL(insert(ring,'i'),SUCCESS);
//// 	CU_ASSERT_EQUAL(insert(ring,'j'),SUCCESS);
//// 	CU_ASSERT_EQUAL(insert(ring,'k'),SUCCESS);
//// 	CU_ASSERT_EQUAL(insert(ring,'l'),SUCCESS);
//// 	CU_ASSERT_EQUAL(insert(ring,'m'),BUFF_FULL);
//
//// 	CU_ASSERT_EQUAL(entries(ring),SUCCESS);
//
//// 	CU_ASSERT_EQUAL(remove_t(ring,&c),SUCCESS);
//// 	CU_ASSERT_EQUAL(remove_t(ring,&c),SUCCESS);
//// 	CU_ASSERT_EQUAL(remove_t(ring,&c),SUCCESS);
//// 	CU_ASSERT_EQUAL(remove_t(ring,&c),SUCCESS);
//// 	CU_ASSERT_EQUAL(remove_t(ring,&c),SUCCESS);
//// 	CU_ASSERT_EQUAL(remove_t(ring,&c),SUCCESS);
//// 	CU_ASSERT_EQUAL(remove_t(ring,&c),SUCCESS);
//// 	CU_ASSERT_EQUAL(remove_t(ring,&c),SUCCESS);
//// 	CU_ASSERT_EQUAL(remove_t(ring,&c),SUCCESS);
//// 	CU_ASSERT_EQUAL(remove_t(ring,&c),SUCCESS);
//// 	CU_ASSERT_EQUAL(remove_t(ring,&c),SUCCESS);
//// 	CU_ASSERT_EQUAL(remove_t(ring,&c),BUFF_EMPTY);
//
//// 	CU_ASSERT_EQUAL(entries(ring),SUCCESS);
//
//// }
//
///* Conditions for checking NULL pointers*/
//// void test_suite3() //suite3
//// {
//// 	char c;
//// 	ring_t *ring = NULL;
//// 	CU_ASSERT_EQUAL(insert(ring,'b'),FAIL);
//// 	CU_ASSERT_EQUAL(remove_t(ring,&c),FAIL);
//
//
//// }
//
//int register_test_suite(void)
//{
// return 0;
//}
//
//int main()
//{
//	//CU_pSuite pSuite1= NULL;
//
//	/* initialize the CUnit test registry */
//	if (CUE_SUCCESS != CU_initialize_registry())
//	  return CU_get_error();
//
//  	if(register_test_suite() == -1)
//  	{
//  		CU_cleanup_registry();
//  		return CU_get_error();
//  	}
//
// 	/* add a suite to the registry */
// 	CU_pSuite pSuite1 = NULL;
// 	pSuite1 = CU_add_suite("Suite_1", init_suite1, clean_suite1);
//	if (NULL == pSuite1)
//	{
//	CU_cleanup_registry();
//	return CU_get_error();
//	}
//	if ((CU_add_test(pSuite1, "test of Circular buffer", test_suite1)) == NULL)
//   {
//      CU_cleanup_registry();
//      return CU_get_error();
//   }
//
///**************************************************************************************************************************************/
// 	/* add a suite to the registry */
//
// //    CU_pSuite pSuite2 = NULL;
// //  	pSuite2 = CU_add_suite("Suite_2", init_suite1, clean_suite1);
//	//  if (NULL == pSuite2)
//	//  {
//	//  CU_cleanup_registry();
//	//  return CU_get_error();
//	//  }
//	//  if ((CU_add_test(pSuite2, "test of Full buffer and empty buffer", test_suite2)) == NULL)
//	// {
//	//   CU_cleanup_registry();
//	//    return CU_get_error();
//	// }
//
///**************************************************************************************************************************************/
// 	/* add a suite to the registry */
//
//	// CU_pSuite pSuite3 = NULL;
// //  	pSuite3 = CU_add_suite("Suite_3", init_suite1, clean_suite1);
//	//  if (NULL == pSuite3)
//	//  {
//	//  CU_cleanup_registry();
//	//  return CU_get_error();
//	//  }
//	//  if ((CU_add_test(pSuite3, "test of NULL conditions", test_suite3)) == NULL)
//	// {
//	//   CU_cleanup_registry();
//	//    return CU_get_error();
//	// }
//
///******************************************************************************************************************************************/
//
//
//   /* Run all tests using the CUnit Basic interface */
//   CU_basic_set_mode(CU_BRM_VERBOSE);
//   CU_basic_run_tests();
//   CU_cleanup_registry();
//   return CU_get_error();
//}
