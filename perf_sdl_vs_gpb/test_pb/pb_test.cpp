#include "pb_def.pb.h"
using namespace protobuf_pb_5fdef_2eproto;
#include <iostream>
using namespace std;
#include <time.h>
#include <sys/time.h>
#include <strstream>
#include <pthread.h>

#define START_TEST(X) struct timezone tmz_##X; struct timeval tvStart_##X;gettimeofday(&tvStart_##X,&tmz_##X);

#define END_TEST(Y) struct timeval tvEnd_##Y; gettimeofday(&tvEnd_##Y,&tmz_##Y); long dur=(tvEnd_##Y.tv_sec*1000000+tvEnd_##Y.tv_usec)-(tvStart_##Y.tv_sec*1000000+tvStart_##Y.tv_usec);

#define DMILL 1000000.0

int g_threads = 1;
int g_rounds = 1;
int g_loop = 100000;


template <class T>
void exec_pb_seria(T& t)
{
	cout<<"tid="<<pthread_self()<<",sizeof(T)="<<sizeof(t) <<" bytes"<<endl;
	string strIn;
	cout<<"---------------------------"<<endl;
	{

		string strOut;
		START_TEST(seria_loop)
		for(int i=0;i<g_loop;i++)
		{
			strOut.clear();
			t.SerializeToString(&strOut);
		}
		END_TEST(seria_loop)
		cout<<"tid="<<pthread_self()<<",serialize duration="<<dur/DMILL<<" sec"<<endl;
		cout<<"tid="<<pthread_self()<<",serialize size="<<strOut.length()<<" bytes"<<endl;
		strIn = strOut;

	}
	cout<<"---------------------------"<<endl;
	{
		START_TEST(seria_loop)
		T tt;
		for(int i=0;i<g_loop;i++)
		{
			tt.Clear();
			tt.ParseFromString(strIn);
		}
		END_TEST(seria_loop)
		//cout<<"sizeof(T)="<<sizeof(tt) <<"bytes"<<endl;
		cout<<"tid="<<pthread_self()<<",deserialize duration="<<dur/DMILL<<" sec"<<endl;

	}
}

typedef void*(*start_routine)(void*);

template<class T>
void multi_thread_exec(T& t, start_routine sr )
{
	cout<<"================================="<<endl;
	START_TEST(total_rounds)
	for(int i=0;i<g_rounds;i++)
	{
		START_TEST(one_round)
		cout<<"round:"<<i<<endl;
		vector<pthread_t> pids;
		pids.resize(g_threads);
		for(int j=0;j<g_threads;j++)
		{
			pthread_t pid = -1;
			if( pthread_create(&pid,NULL,sr,&t) != 0)
			{
				cout<<"create thread error"<<endl;
				return ;
			}
			pids[j] = pid;
			cout<<"create thread id="<<pids[j]<<endl;
		}
		for(int j=0;j<pids.size();j++)
		{
			pthread_join(pids[j],NULL);
		}
		END_TEST(one_round)
		cout<<"one_round duration="<<dur/DMILL<<" sec"<<endl;
	}
	END_TEST(total_rounds)
	cout<<"rounds="<<g_rounds<<",threads="<<g_threads<<",loop="<<g_loop<<",total duration="<<dur/DMILL<<" sec"<<endl;
	cout<<"================================="<<endl;
}

string i2str(int i)
{
        char str[64] = {0};
        snprintf(str,sizeof(str),"%d",i);
        return string(str);
}
void init_int(IntStruct& is)
{
	is.set_i0(1<<0);
	is.set_i1(1<<1);
	is.set_i2(1<<2);
	is.set_i3(1<<3);
	is.set_i4(1<<4);
	is.set_i5(1<<5);
	is.set_i6(1<<6);
	is.set_i7(1<<7);
	is.set_i8(1<<8);
	is.set_i9(1<<9);
	is.set_i10(1<<10);
	is.set_i11(1<<11);
	is.set_i12(1<<12);
	is.set_i13(1<<13);
	is.set_i14(1<<14);
	is.set_i15(1<<15);
	is.set_i16(1<<16);
	is.set_i17(1<<17);
	is.set_i18(1<<18);
	is.set_i19(1<<19);
	is.set_i20(1<<20);
	is.set_i21(1<<21);
	is.set_i22(1<<22);
	is.set_i23(1<<23);
	is.set_i24(1<<24);
	is.set_i25(1<<25);
	is.set_i26(1<<26);
	is.set_i27(1<<27);
	is.set_i28(1<<28);
	is.set_i29(1<<29);
	is.set_i30(1<<30);
	is.set_i31(1<<31);


	is.set_l0(1LL<<0);
	is.set_l1(1LL<<1);
	is.set_l2(1LL<<2);
	is.set_l3(1LL<<3);
	is.set_l4(1LL<<4);
	is.set_l5(1LL<<5);
	is.set_l6(1LL<<6);
	is.set_l7(1LL<<7);
	is.set_l8(1LL<<8);
	is.set_l9(1LL<<9);
	is.set_l10(1LL<<10);
	is.set_l11(1LL<<11);
	is.set_l12(1LL<<12);
	is.set_l13(1LL<<13);
	is.set_l14(1LL<<14);
	is.set_l15(1LL<<15);
	is.set_l16(1LL<<16);
	is.set_l17(1LL<<17);
	is.set_l18(1LL<<18);
	is.set_l19(1LL<<19);
	is.set_l20(1LL<<20);
	is.set_l21(1LL<<21);
	is.set_l22(1LL<<22);
	is.set_l23(1LL<<23);
	is.set_l24(1LL<<24);
	is.set_l25(1LL<<25);
	is.set_l26(1LL<<26);
	is.set_l27(1LL<<27);
	is.set_l28(1LL<<28);
	is.set_l29(1LL<<29);
	is.set_l30(1LL<<30);
	is.set_l31(1LL<<31);
	is.set_l32(1LL<<32);
	is.set_l33(1LL<<33);
	is.set_l34(1LL<<34);
	is.set_l35(1LL<<35);
	is.set_l36(1LL<<36);
	is.set_l37(1LL<<37);
	is.set_l38(1LL<<38);
	is.set_l39(1LL<<39);
	is.set_l40(1LL<<40);
	is.set_l41(1LL<<41);
	is.set_l42(1LL<<42);
	is.set_l43(1LL<<43);
	is.set_l44(1LL<<44);
	is.set_l45(1LL<<45);
	is.set_l46(1LL<<46);
	is.set_l47(1LL<<47);
	is.set_l48(1LL<<48);
	is.set_l49(1LL<<49);
	is.set_l50(1LL<<50);
	is.set_l51(1LL<<51);
	is.set_l52(1LL<<52);
	is.set_l53(1LL<<53);
	is.set_l54(1LL<<54);
	is.set_l55(1LL<<55);
	is.set_l56(1LL<<56);
	is.set_l57(1LL<<57);
	is.set_l58(1LL<<58);
	is.set_l59(1LL<<59);
	is.set_l60(1LL<<60);
	is.set_l61(1LL<<61);
	is.set_l62(1LL<<62);
	is.set_l63(1LL<<63);
}

void* run_int(void* arg)
{
	IntStruct* is = (IntStruct*)arg;
	exec_pb_seria(*is);
}

void test_int()
{
	cout<<"protobuf test int32/int64"<<endl;
	IntStruct is;
	init_int(is);
	multi_thread_exec(is,run_int);
}


void init_string(StringStruct& ss)
{
	string short_str;
	string long_str;
	for(int i=0;i<32;i++) short_str.append("S");
	for(int i=0;i<10240;i++) long_str.append("L");

	ss.set_str1(short_str);
	ss.set_str2(long_str);

}
void* run_string(void* arg)
{
	StringStruct* ss = (StringStruct*)arg;
	exec_pb_seria(*ss);
	return NULL;
}

void test_string()
{
	cout<<"protobuf test string"<<endl;

	StringStruct ss;	
	init_string(ss);
	multi_thread_exec(ss,run_string);
}


void init_map(MapStruct& ms)
{
	START_TEST(init_map)
	string strv;
	string strk;
	for(int i=0;i<1024;i++) strv.append("V");
	for(int i=0;i<32;i++) strk.append("K");

	auto m1=ms.mutable_mapstr2str();
	auto m2=ms.mutable_mapstr2int();
	auto m3=ms.mutable_mapint2str();
	auto m4=ms.mutable_mapint2int();
	for(int i=0;i<1024;i++)
	{
		string strkk = strk + i2str(i);
		(*m1)[strkk]=strv;
		(*m2)[strkk]=1<<20;
		(*m3)[(1<<20)+i]=strv;
		(*m4)[(1<<20)+i]=1<<20;

	}
	END_TEST(init_map)
	cout<<"init_map,duration="<<dur<<" usec"<<endl;
}

void* run_map(void* arg)
{
	MapStruct* ms = (MapStruct*)arg;
	exec_pb_seria(*ms);
	return NULL;
}

void test_map()
{
	cout<<"protobuf test map"<<endl;
	MapStruct ms;
	init_map(ms);
	multi_thread_exec(ms,run_map);
	
}

void init_list(ListStruct& ls)
{
	START_TEST(init_list)
	string strv;
	for(int i=0;i<128;i++)
		strv.append("A");

	for(int i=0;i<1024;i++)
	{
//		int idi = i%32;
//		int idl = i%64;
//		ls.add_lstint(1<<idi);
//		ls.add_lstlong(1<<idl);
//		string strvv = strv + i2str(i);
		ls.add_lststr(strv);
	}
	END_TEST(init_list)
	cout<<"init_list,duration="<<dur<<" usec"<<endl;
}
void* run_list(void* arg)
{
	ListStruct* ls = (ListStruct*)arg;
	exec_pb_seria(*ls);
	return NULL;
}
void test_list()
{
	cout<<"protobuf test list"<<endl;
	ListStruct ls;
	init_list(ls);
	multi_thread_exec(ls,run_list);

}

void init_maplist(MapListStruct& mls)
{
	START_TEST(init_maplist)
	auto mili = mls.mutable_mili();//map<int,list<int> >
	auto msls = mls.mutable_msls();//map<string,list<string> >
	string  strV;
	for(int i=0;i<32;i++) strV.append("A");
	for(int i=0;i<1024;i++)
	{
		MapListStruct_ListIntValue liv;
		MapListStruct_ListStrValue lsv;
		for(int j=0;j<1024;j++)
		{
			int idj = j%32;
			liv.add_v(1<<idj);
			lsv.add_v(strV);
		}
		(*mili)[i] = liv;
		string strK = strV+i2str(i);
		(*msls)[strK] = lsv;
	}
	END_TEST(init_maplist)
	cout<<"init_maplist,duration="<<dur<<" usec"<<endl;
}
void* run_maplist(void* arg)
{
	MapListStruct* mls = (MapListStruct*)arg;
	exec_pb_seria(*mls);
	return NULL;
}
void test_maplist()
{
	cout<<"protobuf test maplist"<<endl;
	MapListStruct mls;
	init_maplist(mls);
	multi_thread_exec(mls,run_maplist);
}


void init_mapmap(MapMapStruct& mms)
{
	START_TEST(init_mapmap)
	auto mimii=mms.mutable_mimii();
	auto msmss=mms.mutable_msmss();
	string  strV;
		for(int i=0;i<32;i++) strV.append("A");
		for(int i=0;i<1024;i++)
	{
		MapMapStruct_MapIntValue mii;
		MapMapStruct_MapStrValue mss;
		auto miiv = mii.mutable_v();
		auto mssv = mss.mutable_v();
		for(int j=0;j<1024;j++)
		{
			int idj = j%32;
			string strK = strV+i2str(j);
			(*miiv)[j] = 1<<idj;
			(*mssv)[strK] = strV;
		}
		(*mimii)[i] = mii;	
		string strK = strV+i2str(i);
		(*msmss)[strK] = mss;
	}
	END_TEST(init_mapmap)
	cout<<"init_mapmap,duration="<<dur<<" usec"<<endl;
}
void* run_mapmap(void* arg)
{
	MapMapStruct* mms = (MapMapStruct*)arg;
	exec_pb_seria(*mms);
	return NULL;
}
void test_mapmap()
{
	cout<<"protobuf test mapmap"<<endl;
	MapMapStruct mms;
	init_mapmap(mms);
	multi_thread_exec(mms,run_mapmap);
	
}


void init_listmap(ListMapStruct& lms)
{
	START_TEST(init_listmap)
	auto lmii=lms.mutable_lmi();
	auto lmss=lms.mutable_lms();
	string  strV;
	for(int i=0;i<32;i++) strV.append("A");
	for(int i=0;i<1024;i++)
	{
		ListMapStruct_MapIntValue  mii;
		ListMapStruct_MapStrValue mss;
		auto miiv = mii.mutable_v();
		auto mssv = mss.mutable_v();
		for(int j=0;j<1024;j++)
		{
			int idj = j%32;
			string strK = strV+i2str(j);
			(*miiv)[j] = 1<<idj;
			(*mssv)[strK] = strV;
		}
		(*lms.add_lmi()) = mii;
		(*lms.add_lms()) = mss;
	}
	END_TEST(init_listmap)
	cout<<"init_listmap,duration="<<dur<<" usec"<<endl;
}
void* run_listmap(void* arg)
{
	auto* lms = (ListMapStruct*)arg;
	exec_pb_seria(*lms);
	return NULL;
}
void test_listmap()
{
	cout<<"protobuf test listmap"<<endl;
	ListMapStruct lms;
	init_listmap(lms);
	multi_thread_exec(lms,run_listmap);
}

void init_listlist(ListListStruct& lls)
{
	START_TEST(init_listlist)
	string  strV;
	for(int i=0;i<32;i++) strV.append("A");
	for(int i=0;i<1024;i++)
	{
		ListListStruct_ListIntValue  li;
		ListListStruct_ListStrValue ls;
		auto liv = li.mutable_v();
		auto lsv = ls.mutable_v();
		for(int j=0;j<1024;j++)
		{
			int idj = j%32;
			li.add_v(1<<idj);
			ls.add_v(strV);
		}
	(*lls.add_li()) = li;
	(*lls.add_ls()) = ls;
	}
	END_TEST(init_listlist)
	cout<<"init_listlist,duration="<<dur<<" usec"<<endl;

}

void* run_listlist(void* arg)
{
	auto* lls = (ListListStruct*)arg;
	exec_pb_seria(*lls);
	return NULL;
}

void test_listlist()
{
	cout<<"protobuf test listlist"<<endl;
	ListListStruct lls;
	init_listlist(lls);
	multi_thread_exec(lls,run_listlist);
}


int main(int argc,char* argv[])
{
	if(argc == 4)
	{
		g_rounds = atoi(argv[1]);
		g_threads = atoi(argv[2]);
		g_loop = atoi(argv[3]);
	}
	//test_int();
	//test_string();
	//test_map();
	test_list();
	//test_maplist();
	//test_mapmap();
//	test_listmap();
//	test_listlist();
	return 0;
}

