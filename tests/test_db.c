 /**
  * Copyright 2019 Comcast Cable Communications Management, LLC
  *
  * Licensed under the Apache License, Version 2.0 (the "License");
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  *
  *     http://www.apache.org/licenses/LICENSE-2.0
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
 */
#include <stdint.h>
#include <errno.h>
#include <stdio.h>
#include <CUnit/Basic.h>
#include "../src/webcfg_db.h"
#include "../src/webcfg_pack.h"
#include "../src/webcfg_helpers.h"
#include "../src/webcfg_param.h"
#include "../src/webcfg_multipart.h"
#include "../src/webcfg_timer.h"
#include "../src/webcfg_notify.h"
#define UNUSED(x) (void )(x)
//mock functions

bool get_global_shutdown()
{
	return false;
}
int akerwait__ (unsigned int secs)
{
	UNUSED(secs);
	return 0;

}
char *getAuthToken()
{
	return NULL;
}
char* get_deviceMAC()
{
	char *device_mac=strdup("b42xxxxxxxxx");
	return device_mac;
}
int Get_Webconfig_URL( char *pString)
{
	char *webConfigURL =NULL;
	loadInitURLFromFile(&webConfigURL);
	pString = webConfigURL;
        printf("The value of pString is %s\n",pString);
	return 0;
}
int Set_Webconfig_URL( char *pString)
{
	printf("Set_Webconfig_URL pString %s\n", pString);
	return 0;
}

char * webcfg_appendeddoc(char * subdoc_name, uint32_t version, char * blob_data, size_t blob_size, uint16_t *trans_id)
{
	UNUSED(subdoc_name);
	UNUSED(version);
	UNUSED(blob_data);
	UNUSED(blob_size);
	UNUSED(trans_id);
	return NULL;
}

void initEventHandlingTask(){
	return;
}

void processWebcfgEvents(){
	return;
}

void webcfgStrncpy(char *destStr, const char *srcStr, size_t destSize)
{
    strncpy(destStr, srcStr, destSize-1);
    destStr[destSize-1] = '\0';
}

WEBCFG_STATUS checkAndUpdateTmpRetryCount(webconfig_tmp_data_t *temp, char *docname)
{
	UNUSED(temp);
	UNUSED(docname);
	return 0;
}
void setValues(const param_t paramVal[], const unsigned int paramCount, const int setType, char *transactionId, money_trace_spans *timeSpan, WDMP_STATUS *retStatus, int *ccspStatus)
{
	UNUSED(paramVal);
	UNUSED(paramCount);
	UNUSED(setType);
	UNUSED(transactionId);
	UNUSED(timeSpan);
	UNUSED(retStatus);
	UNUSED(ccspStatus);
	return;
}


void sendNotification(char *payload, char *source, char *destination)
{
	WEBCFG_FREE(payload);
	WEBCFG_FREE(source);
	UNUSED(destination);
	return;
}

WDMP_STATUS mapStatus(int ret)
{
	UNUSED(ret);
	return 0;
}


void isSubDocSupported(){
	return;

}

void checkAkerStatus(){
	
	return;
}
void updateAkerMaxRetry(webconfig_tmp_data_t *temp, char *docname)
{
	UNUSED(temp);
	UNUSED(docname);
	return;
}

void processAkerSubdoc(){
return ;
}


char * getsupportedDocs()
{
	return NULL;
}
char * getsupportedVersion()
{
	return NULL;
}

char * getDeviceBootTime()
{
	char *bTime = strdup("152200345");
	return bTime;
}

char * getFirmwareVersion()
{
	char *fName = strdup("Firmware.bin");
	return fName;
}

int getForceSync(char** pString, char **transactionId)
{
	UNUSED(pString);
	UNUSED(transactionId);
	return 0;
}

char * getProductClass()
{
	char *pClass = strdup("Product");
	return pClass;
}

char * getModelName()
{
	char *mName = strdup("Model");
	return mName;
}


void retryMultipartSubdoc(){
	return ;
}
char *get_global_systemReadyTime()
{
	char *sTime = strdup("158000123");
	return sTime;
}

char * getRebootReason()
{
	char *reason = strdup("factory-reset");
	return reason;
}

char* get_global_auth_token(){
	char *tok = strdup("1234567890");
	return tok ;
}
void getCurrent_Time(struct timespec *timer){
	UNUSED(timer);
	return;
}


char * getPartnerID()
{
	char *pID = strdup("partnerID");
	return pID;
}

char * getAccountID()
{
	char *aID = strdup("accountID");
	return aID;
}

void set_global_supplementarySync(int value)
{
    UNUSED(value);
}

int get_global_supplementarySync()
{
	return 0;
}


int Get_Supplementary_URL( char *name, char *pString)
{
    UNUSED(name);
    UNUSED(pString);
    return 0;
}

int Set_Supplementary_URL( char *name, char *pString)
{
    UNUSED(name);
    UNUSED(pString);
    return 0;
}
char *getFirmwareUpgradeStartTime(void)
{
    return NULL;
}

char *getFirmwareUpgradeEndTime(void)
{
    return NULL;
}
char * getsupplementaryDocs()
{
      return NULL;
}
int generateRandomId()
{
	return 0;
}

/*----------------------------------------------------------------------------*/
/*                             Test Functions                             */
/*----------------------------------------------------------------------------*/




void test_blobPackUnpack(){
	size_t webcfgdbBlobPackSize = -1;
    	void * data = NULL;
	webconfig_db_data_t * webcfgdb = NULL;
	webconfig_tmp_data_t *webcfgtemp;
	webconfig_db_data_t *db_data;
    	webconfig_tmp_data_t *temp_data;
	//db data	
	webcfgdb = (webconfig_db_data_t *) malloc (sizeof(webconfig_db_data_t));
	webcfgdb->name = strdup("wan");
	webcfgdb->version = 410448631;
	webcfgdb->root_string = strdup("portmapping");
	webcfgdb->next=NULL;
	//temp data
	webcfgtemp=(webconfig_tmp_data_t *)malloc(sizeof(webconfig_tmp_data_t));
	webcfgtemp->name = strdup("wan");
	webcfgtemp->version = 410448631;
	webcfgtemp->status = strdup("pending");
	webcfgtemp->error_details = strdup("none");
	webcfgtemp->error_code = 0;
	webcfgtemp->trans_id = 0;
	webcfgtemp->retry_count = 0;
	webcfgtemp->next=NULL;
	//webcfgdb_blob_pack function
	
 	webcfgdbBlobPackSize = webcfgdb_blob_pack(webcfgdb, webcfgtemp, &data);
	db_data = webcfgdb;
    	temp_data = webcfgtemp;
	CU_ASSERT_PTR_NOT_NULL(webcfgdbBlobPackSize);
	CU_ASSERT_PTR_NOT_NULL(db_data);
	CU_ASSERT_PTR_NOT_NULL(temp_data);
	
	//decodeBlobData
	blob_struct_t *blobdata = NULL;
	blobdata = decodeBlobData((void *)data, webcfgdbBlobPackSize );
	CU_ASSERT_PTR_NOT_NULL(blobdata);
	CU_ASSERT_STRING_EQUAL("wan",blobdata->entries[0].name);
	CU_ASSERT_EQUAL(410448631,blobdata->entries[0].version);
	CU_ASSERT_STRING_EQUAL("success",blobdata->entries[0].status);
	CU_ASSERT_STRING_EQUAL("none",blobdata->entries[0].error_details);
	CU_ASSERT_EQUAL(0,blobdata->entries[0].error_code);
	CU_ASSERT_STRING_EQUAL("portmapping",blobdata->entries[0].root_string);
	webcfgdbblob_destroy(blobdata);
	
}

void test_dbPackUnpack(){
	size_t webcfgdbPackSize = -1;
     	void* dbData = NULL;
	size_t count=1;
	webconfig_db_data_t * webcfgdb = NULL;
	
	//db data	
	webcfgdb = (webconfig_db_data_t *) malloc (sizeof(webconfig_db_data_t));
	webcfgdb->name = strdup("wan");
	webcfgdb->version = 410448631;
	webcfgdb->root_string = strdup("portmapping");
	webcfgdb->next=NULL;
	
	//webcfgdb_pack function
	
 	webcfgdbPackSize = webcfgdb_pack(webcfgdb, &dbData, count);
	
	CU_ASSERT_PTR_NOT_NULL(webcfgdbPackSize);
	CU_ASSERT_PTR_NOT_NULL(dbData);
	//decodeData
	webconfig_db_data_t* sss =NULL;
	sss = decodeData((void *)dbData, webcfgdbPackSize );
	CU_ASSERT_PTR_NOT_NULL(sss);
	webcfgdb_destroy(sss);
	
}

void test_addToDBList(){
	webconfig_db_data_t *wd;
	wd = (webconfig_db_data_t *) malloc (sizeof(webconfig_db_data_t));
	CU_ASSERT_PTR_NOT_NULL(wd);
	wd->name = strdup("wan");
	wd->version = 410448631;
	wd->root_string = strdup("portmapping");
	wd->next=NULL;
        addToDBList(wd);
	WEBCFG_FREE(wd);
}

void test_addToTmpList(){
	webconfig_tmp_data_t *wd;
	wd = (webconfig_tmp_data_t *)malloc(sizeof(webconfig_tmp_data_t));
	wd->name = strdup("moca");
	wd->version=56857233;
	wd->status = strdup("Pending");
	wd->error_details = strdup("none");
	wd->retry_count=0;
	wd->error_code=0;
	wd->trans_id=0;
	wd->isSupplementarySync=0;
	wd->retry_timestamp=28;
	wd->next=NULL;
	addToTmpList();

	CU_ASSERT_STRING_EQUAL("moca",wd->name);
	WEBCFG_FREE(wd);
}

void test_webcfgdbblob_strerror(){
	const char *p=webcfgdbblob_strerror(0);
	printf("\n%s\n",p); 
	CU_ASSERT_STRING_EQUAL(p, "No errors.")
	p=webcfgdbblob_strerror(1);
	printf("%s\n", p);
	CU_ASSERT_STRING_EQUAL(p, "Out of memory.");
	p=webcfgdbblob_strerror(2);
        printf("%s\n", p);
        CU_ASSERT_STRING_EQUAL(p, "Invalid first element.");
	p=webcfgdbblob_strerror(3);
        printf("%s\n", p);
        CU_ASSERT_STRING_EQUAL(p, "Invalid 'datatype' value.");
	p=webcfgdbblob_strerror(4);
        printf("%s\n", p);
        CU_ASSERT_STRING_EQUAL(p, "Invalid 'parameters' array.");
	p=webcfgdbblob_strerror(5);
        printf("%s\n", p);
        CU_ASSERT_STRING_EQUAL(p, "Unknown error.");	
}

void test_webcfgdbparam_strerror(){
	const char *p=webcfgdbblob_strerror(0);
        printf("\n%s\n",p);
        CU_ASSERT_STRING_EQUAL(p, "No errors.")
        p=webcfgdbblob_strerror(1);
        printf("%s\n", p);
        CU_ASSERT_STRING_EQUAL(p, "Out of memory.");
        p=webcfgdbblob_strerror(2);
        printf("%s\n", p);
        CU_ASSERT_STRING_EQUAL(p, "Invalid first element.");
        p=webcfgdbblob_strerror(3);
        printf("%s\n", p);
        CU_ASSERT_STRING_EQUAL(p, "Invalid 'datatype' value.");
        p=webcfgdbblob_strerror(4);
        printf("%s\n", p);
        CU_ASSERT_STRING_EQUAL(p, "Invalid 'parameters' array.");
        p=webcfgdbblob_strerror(5);
        printf("%s\n", p);
        CU_ASSERT_STRING_EQUAL(p, "Unknown error.");
}

void test_writeToDBFile_success(){
	//if data not equal to null and file path is proper it should return 1
	char *data = "Hello";
       	size_t size=10;	
	int output = writeToDBFile(WEBCFG_DB_FILE, data, size);
	printf("%d\n", output);
	CU_ASSERT_EQUAL(output , 1);
}

void test_writeToDBFile_fail(){
	//if data is equal to NULL it should return 0
	char *data=NULL;
	size_t size=10;
	int output = writeToDBFile(WEBCFG_DB_FILE, data, size);
	printf("%d\n", output);
	CU_ASSERT_EQUAL(output, 0);
}

void test_deleteFromTmpList(){
	webconfig_tmp_data_t *webcfgtemp=NULL;
	webcfgtemp=(webconfig_tmp_data_t *)malloc(sizeof(webconfig_tmp_data_t));
	webcfgtemp->name = strdup("wan");
	webcfgtemp->version = 410448631;
	webcfgtemp->status = strdup("pending");
	webcfgtemp->error_details = strdup("none");
	webcfgtemp->error_code = 0;
	webcfgtemp->trans_id = 0;
	webcfgtemp->retry_count = 0;
	webcfgtemp->next=NULL;

	set_global_tmp_node(webcfgtemp);

	webconfig_tmp_data_t *temp=get_global_tmp_node();

	//check for the tmp return value
	CU_ASSERT_PTR_NOT_NULL(temp);

	//doc_name is equal to null 
	char *docname = NULL;
	int output=deleteFromTmpList(docname, &webcfgtemp);
	printf("%d\n", output);
	CU_ASSERT_NOT_EQUAL(output, 0);

	//doc_name which is not present
	docname = "moca";
	output=deleteFromTmpList(docname, &webcfgtemp);
	CU_ASSERT_NOT_EQUAL(output, 0);

	//doc_name which is present 
	docname ="wan";
	output=deleteFromTmpList(docname, &webcfgtemp);
	CU_ASSERT_EQUAL(output,0);
	
	
}

void test_updateTmpList(){
	webconfig_tmp_data_t *webcfgtemp=NULL;
        webcfgtemp=(webconfig_tmp_data_t *)malloc(sizeof(webconfig_tmp_data_t));
        webcfgtemp->name = strdup("wan");
        webcfgtemp->version = 410448631;
        webcfgtemp->status = strdup("pending");
        webcfgtemp->error_details = strdup("none");
        webcfgtemp->error_code = 0;
        webcfgtemp->trans_id = 0;
        webcfgtemp->retry_count = 0;
        webcfgtemp->next=NULL;
	
	set_global_tmp_node(webcfgtemp);
	
	//docname not in the tmp list
	char *docname="moca";
	uint32_t version=123456789;
	char *status="sent";
	char *error_details = "pending";
	uint16_t error_code = 404;
	uint16_t trans_id = 1;
	int retry =0;

	int output=updateTmpList(webcfgtemp, docname, version, status, error_details, error_code, trans_id, retry);
	CU_ASSERT_NOT_EQUAL(output, 0);

	//docname is present
	docname="wan";
	output=updateTmpList(webcfgtemp, docname, version, status, error_details, error_code, trans_id, retry);
	CU_ASSERT_EQUAL(output,0);

	//same status, error_details 
	status="pending";
	error_details="none";
	output=updateTmpList(webcfgtemp, docname, version, status, error_details, error_code, trans_id, retry);
        CU_ASSERT_EQUAL(output,0);

}

void test_getTmpNode(){
	webconfig_tmp_data_t *webcfgtemp=NULL;
        webcfgtemp=(webconfig_tmp_data_t *)malloc(sizeof(webconfig_tmp_data_t));
        webcfgtemp->name = strdup("wan");
        webcfgtemp->version = 410448631;
        webcfgtemp->status = strdup("pending");
        webcfgtemp->error_details = strdup("none");
        webcfgtemp->error_code = 0;
        webcfgtemp->trans_id = 0;
        webcfgtemp->retry_count = 0;
        webcfgtemp->next=NULL;

        set_global_tmp_node(webcfgtemp);

	//docname which is not present
	char *docname="moca";
	webconfig_tmp_data_t *tmp = getTmpNode(docname);
	CU_ASSERT_PTR_NULL(tmp);

	//with proper docname
	docname="wan";
	tmp = getTmpNode(docname);
	CU_ASSERT_PTR_NOT_NULL(tmp);

}

void test_delete_tmp_list(){
	webconfig_tmp_data_t *webcfgtemp=NULL;
        webcfgtemp=(webconfig_tmp_data_t *)malloc(sizeof(webconfig_tmp_data_t));
        webcfgtemp->name = strdup("wan");
        webcfgtemp->version = 410448631;
        webcfgtemp->status = strdup("pending");
        webcfgtemp->error_details = strdup("none");
        webcfgtemp->error_code = 0;
        webcfgtemp->trans_id = 0;
        webcfgtemp->retry_count = 0;
        webcfgtemp->next=NULL;

        set_global_tmp_node(webcfgtemp);
	webconfig_tmp_data_t *tmp=get_global_tmp_node();

	//values present before calling the function
	CU_ASSERT_PTR_NOT_NULL(tmp);
	delete_tmp_list();

	//pointer null after calling the function
	tmp=get_global_tmp_node();
	CU_ASSERT_PTR_NULL(tmp);
}

void test_delete_tmp_docs_list(){
	webconfig_tmp_data_t *webcfgtemp=NULL;
        webcfgtemp=(webconfig_tmp_data_t *)malloc(sizeof(webconfig_tmp_data_t));
        webcfgtemp->name = strdup("root");
        webcfgtemp->version = 0;
        webcfgtemp->status = strdup("success");
        webcfgtemp->error_details = strdup("none");
        webcfgtemp->error_code = 0;
        webcfgtemp->trans_id = 0;
        webcfgtemp->retry_count = 0;
        webcfgtemp->next=NULL;

	set_global_tmp_node(webcfgtemp);
        webconfig_tmp_data_t *tmp=get_global_tmp_node();

	//value is not deleted when name=root
	delete_tmp_docs_list();
	CU_ASSERT_PTR_NOT_NULL(tmp);

	//value gets deleted when name is any thing other than root
	WEBCFG_FREE(webcfgtemp->name);
	webcfgtemp->name=strdup("moca");
	webcfgtemp->version=56857233;
	delete_tmp_docs_list();

	tmp=get_global_tmp_node();
	CU_ASSERT_PTR_NULL(tmp);
}

void test_release_success_docs_tmplist(){
	webconfig_tmp_data_t *webcfgtemp=NULL;
        webcfgtemp=(webconfig_tmp_data_t *)malloc(sizeof(webconfig_tmp_data_t));
        webcfgtemp->name = strdup("wan");
        webcfgtemp->version = 410448631;
        webcfgtemp->status = strdup("NULL");
        webcfgtemp->error_details = strdup("none");
        webcfgtemp->error_code = 0;
        webcfgtemp->trans_id = 0;
        webcfgtemp->retry_count = 0;
        webcfgtemp->next=NULL;
	set_global_tmp_node(webcfgtemp);
        webconfig_tmp_data_t *tmp=get_global_tmp_node();

	//status equal to null
	release_success_docs_tmplist();
	CU_ASSERT_PTR_NOT_NULL(tmp);

	//status not equal to success
	WEBCFG_FREE(webcfgtemp->status);
	webcfgtemp->status=strdup("pending");
	release_success_docs_tmplist();
	CU_ASSERT_PTR_NOT_NULL(tmp);

	//status not equal to null and equal to success
	WEBCFG_FREE(webcfgtemp->status);
	webcfgtemp->status=strdup("success");
}

void test_doc_fail(){
	set_doc_fail(2);
	int value=get_doc_fail();
	CU_ASSERT_EQUAL(2,value);
	CU_ASSERT_NOT_EQUAL(1,value);
}



void test_updateDBlist(){
	webconfig_db_data_t * webcfgdb = NULL;
	webcfgdb = (webconfig_db_data_t *) malloc (sizeof(webconfig_db_data_t));

	webcfgdb->name = strdup("wan");
	webcfgdb->version = 410448631;
	webcfgdb->root_string = NULL;
	webcfgdb->next=NULL;
	
	//name not equal to root
	WEBCFG_STATUS wd;
	wd=updateDBlist("wan", 2345678, "portmapping");	
	CU_ASSERT_EQUAL(0,wd);
		
	//name equal to root
	webcfgdb->name=strdup("root");
	wd=updateDBlist("root", 234536, "portmapping");
	
	webconfig_db_data_t *dbValue = NULL;
	dbValue=get_global_db_node();
	
	//check if the version is changed
	CU_ASSERT_EQUAL(2345678, dbValue->version);

	//check if the null value of root_string is updated
	CU_ASSERT_STRING_EQUAL("portmapping", dbValue->root_string);
		
}

void test_checkDBList(){
	reset_db_node();
	webconfig_db_data_t * webcfgdb = NULL;
        webcfgdb = (webconfig_db_data_t *) malloc (sizeof(webconfig_db_data_t));

        webcfgdb->name = strdup("wan");
        webcfgdb->version = 410448631;
        webcfgdb->root_string = NULL;
        webcfgdb->next=NULL;
	
	//root_string=NULL
	checkDBList("moca", 234456, "portmapping");
	webconfig_db_data_t *dbValue = NULL;
        dbValue=get_global_db_node();
	
	CU_ASSERT_STRING_EQUAL("moca",dbValue->name);
	
	//root_string not equal to null
	webcfgdb->name = strdup("wan");
        webcfgdb->version = 410448631;
        webcfgdb->root_string = "portmapping";
        webcfgdb->next=NULL;
	
	dbValue=get_global_db_node();
	checkDBList("privatessid", 23456, "portmapping");
}

void test_numOfMpDocs(){
	int x=get_numOfMpDocs();
	CU_ASSERT_NOT_EQUAL(0, x);
	reset_numOfMpDocs();
	x=get_numOfMpDocs();
	CU_ASSERT_EQUAL(0, x);
}

void test_successDocCount(){
	int x=get_successDocCount();
	CU_ASSERT_NOT_EQUAL(0, x);
	reset_successDocCount();
	x=get_successDocCount();
	CU_ASSERT_EQUAL(0, x);
}


void add_suites( CU_pSuite *suite )
{
    *suite = CU_add_suite( "tests", NULL, NULL );
    CU_add_test( *suite, "test blobPackUnpack", test_blobPackUnpack);
    CU_add_test( *suite, "test dbPackUnpack", test_dbPackUnpack);
    CU_add_test( *suite, "test addToDBList", test_addToDBList);
    CU_add_test( *suite, "test addToTmpList", test_addToTmpList);
    CU_add_test( *suite, "test webcfgdbblob strerror", test_webcfgdbblob_strerror);
    CU_add_test( *suite, "test webcfgdbparam strerror", test_webcfgdbparam_strerror);
    CU_add_test( *suite, "test writeToDBFile success", test_writeToDBFile_success);
    CU_add_test( *suite, "test writeToDBFile fail", test_writeToDBFile_fail);
    CU_add_test( *suite, "test deleteFromTmpList", test_deleteFromTmpList);
    CU_add_test( *suite, "test updateTmpList", test_updateTmpList);
    CU_add_test( *suite, "test getTmpNode", test_getTmpNode);
    CU_add_test( *suite, "test delete_tmp_list", test_delete_tmp_list);
    CU_add_test( *suite, "test delete_tmp_docs_list", test_delete_tmp_docs_list);
    CU_add_test( *suite, "test release_success_docs_tmplist", test_release_success_docs_tmplist);
    CU_add_test( *suite, "test doc_fail", test_doc_fail);
    CU_add_test( *suite, "test updateDBlist", test_updateDBlist);
    CU_add_test( *suite, "test checkDBList", test_checkDBList);
    CU_add_test( *suite, "test numOfMpDocs", test_numOfMpDocs);
    CU_add_test( *suite, "test successDocCount", test_successDocCount);
}

/*----------------------------------------------------------------------------*/
/*                             External Functions                             */
/*----------------------------------------------------------------------------*/
int main( int argc, char *argv[] )
{
    unsigned rv = 1;
    CU_pSuite suite = NULL;
 
    (void ) argc;
    (void ) argv;
    
    if( CUE_SUCCESS == CU_initialize_registry() ) {
        add_suites( &suite );

        if( NULL != suite ) {
            CU_basic_set_mode( CU_BRM_VERBOSE );
            CU_basic_run_tests();
            printf( "\n" );
            CU_basic_show_failures( CU_get_failure_list() );
            printf( "\n\n" );
            rv = CU_get_number_of_tests_failed();
        }

        CU_cleanup_registry();

    }

    return rv;
}
