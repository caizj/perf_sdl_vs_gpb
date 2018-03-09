#include "sdl_def_sdl_c.h"
//#include "user_mdb_analyse_def_sdl_c.h"

#include <iostream>
using namespace std;
#include <time.h>
#include <sys/time.h>
#include <pthread.h>

#define START_TEST(X) struct timezone tmz_##X; struct timeval tvStart_##X;gettimeofday(&tvStart_##X,&tmz_##X);

#define END_TEST(Y) struct timeval tvEnd_##Y; gettimeofday(&tvEnd_##Y,&tmz_##Y); long dur=(tvEnd_##Y.tv_sec*1000000+tvEnd_##Y.tv_usec)-(tvStart_##Y.tv_sec*1000000+tvStart_##Y.tv_usec);

#define DMILL 1000000.0

int g_threads = 1;
int g_rounds = 1;
int g_loop = 100000;

template<class T>
void exec_sdl_seria(T& t)
{
	cout<<"tid="<<pthread_self()<<",sizeof(T)="<<sizeof(t)<<" bytes"<<endl;
	string strIn;
	//	sdl::ostream osm;
	cout<<"-----------------------"<<endl;
	{

		START_TEST(seria_loop)
		string strOut;
		sdl::ostream osm;
		for(int i=0;i<g_loop;i++)
		{
			strOut.clear();
			osm(strOut);
			osm << t << sdl::end;
		}
		END_TEST(seria_loop)
		cout<<"tid="<<pthread_self()<<",serialize duration="<<dur/DMILL<<" sec"<<endl;
		cout<<"tid="<<pthread_self()<<",serialize size="<<strOut.size()<<" bytes"<<endl;
		strIn = strOut;
	}
	cout<<"-----------------------"<<endl;

	{
		START_TEST(deseria_loop)
		T tt;
		for(int i=0;i<g_loop;i++)
		{
	//		cout<<"i="<<i<<endl;
			tt.Clear();
			//T tt;
			sdl::istream ism;
			ism(strIn);
			ism >> tt >> sdl::end;
		}
		END_TEST(deseria_loop)
		//cout<<"sizeof(T)="<<sizeof(tt)<<" bytes"<<endl;
		cout<<"tid="<<pthread_self()<<",deserialize duration="<<dur/DMILL<<" sec"<<endl;

	}
	cout<<"-----------------------"<<endl;
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
	cout<<"rounds="<<g_rounds<<",threads="<<g_threads<<",total duration="<<dur/DMILL<<" sec"<<endl;
	cout<<"================================="<<endl;
}

string i2str(int i)
{
	char str[64] = {0};
	snprintf(str,sizeof(str),"%d",i);
	return string(str);
}
void init_int(MBenchmark::SIntStruct& is)
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

	MBenchmark::SIntStruct* is = (MBenchmark::SIntStruct*)arg;

	exec_sdl_seria(*is);

	return NULL;
}

void test_int()
{
	cout<<"sdlbuffer test int32/int64"<<endl;
	MBenchmark::SIntStruct is;
	init_int(is);
	multi_thread_exec(is,run_int);
}


void init_string(MBenchmark::SStringStr& ss)
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
	MBenchmark::SStringStr* ss = (MBenchmark::SStringStr*)arg;
	exec_sdl_seria(*ss);
	return NULL;
}
void test_string()
{
	cout<<"sdlbuffer test string"<<endl;

	MBenchmark::SStringStr ss;
	init_string(ss);
	multi_thread_exec(ss,run_string);
}

void init_map(MBenchmark::SMapStruct& ms)
{
	START_TEST(init_map)
	string strv;
	string strk;
	auto& m1 = ms.mss();
	auto& m2 = ms.msi();
	auto& m3 = ms.mis();
	auto& m4 = ms.mii();
	for(int i=0;i<1024;i++) strv.append("V");
	for(int i=0;i<32;i++) strk.append("K");
	for(int i=0;i<1024;i++)
	{
		string strkk = strk + i2str(i);
		m1[strkk]=strv;
		m2[strkk]=1<<20;
		m3[(1<<20)+i]=strv;
		m4[(1<<20)+i]=1<<20;
	}
	END_TEST(init_map)
	cout<<"init_map,duration="<<dur<<" usec"<<endl;
}
void* run_map(void* arg)
{
	MBenchmark::SMapStruct* ms = (MBenchmark::SMapStruct*)arg;
	exec_sdl_seria(*ms);
	return NULL;
}
void test_map()
{
	cout<<"sdlbuffer test map"<<endl;
	MBenchmark::SMapStruct ms;
	init_map(ms);
	multi_thread_exec(ms,run_map);
}

void init_list(MBenchmark::SListStruct& ls)
{
	START_TEST(init_list)
	string strv;
	for(int i=0;i<128;i++)
		strv.append("A");

	auto& l1 = ls.il();
	auto& l2 = ls.ll();
	auto& l3 = ls.sl();
	for(int i=0;i<1024;i++)
	{
		int idi = i%32;
		int idl = i%64;
		l1.push_back(1<<idi);
		l2.push_back(1<<idl);
		string strvv = strv +  i2str(i);
		l3.push_back(strv);
	}
	END_TEST(init_list)

}
void* run_list(void* arg)
{
	MBenchmark::SListStruct* ls = (MBenchmark::SListStruct*)arg;
	exec_sdl_seria(*ls);
	return NULL;
}
void test_list()
{
	cout<<"sdlbuffer test list"<<endl;
	MBenchmark::SListStruct ls;
	init_list(ls);
	multi_thread_exec(ls,run_list);
}



void init_maplist(MBenchmark::SMapListStruct& mls)
{
	START_TEST(init_maplist)
	auto& mili = mls.mili();
	auto& msls = mls.msls();
	string  strV;
		for(int i=0;i<32;i++) strV.append("A");

	for(int i=0;i<1024;i++)
	{
		MBenchmark::IntList il;
		MBenchmark::StrList sl;
		for(int j=0;j<1024;j++)
		{
			int idj = j%32;
			il.push_back(1<<idj);
			sl.push_back(strV);
		}
		mili[i] = il;

		string strK = strV+i2str(i);
		msls[strK] = sl;
	}
	END_TEST(init_maplist)
	cout<<"init_maplist,duration="<<dur<<" usec"<<endl;

}
void* run_maplist(void* arg)
{
	MBenchmark::SMapListStruct* mls = (MBenchmark::SMapListStruct*)arg;
	exec_sdl_seria(*mls);
	return NULL;
}
void test_maplist()
{
	cout<<"sdlbuffer test maplist"<<endl;
	MBenchmark::SMapListStruct mls;
	init_maplist(mls);
	multi_thread_exec(mls,run_maplist);
}


void init_mapmap(MBenchmark::SMapMapStruct& mms)
{
	START_TEST(init_mapmap)
	auto& mimii = mms.mimii();
	auto& msmss = mms.msmss();
	string  strV;
		for(int i=0;i<32;i++) strV.append("A");
	for(int i=0;i<1024;i++)
	{
		MBenchmark::Int2IntMap mii;
		MBenchmark::Str2StrMap mss;
		for(int j=0;j<1024;j++)
		{
			int idj = j%32;
					string strK = strV+i2str(j);
			mii[j] = 1<<idj;
			mss[strK] = strV;
		}
		mimii[i] = mii;
		string strK = strV+i2str(i);
		msmss[strK] = mss;
	}
	END_TEST(init_mapmap)
	cout<<"init_mapmap,duration="<<dur<<" usec"<<endl;
}
void* run_mapmap(void* arg)
{
	MBenchmark::SMapMapStruct* mms = (MBenchmark::SMapMapStruct*)arg;
	exec_sdl_seria(*mms);
	return NULL;
}
void test_mapmap()
{
	cout<<"sdlbuffer test mapmap"<<endl;
	MBenchmark::SMapMapStruct mms;
	init_mapmap(mms);
	multi_thread_exec(mms,run_mapmap);

}


void init_listmap(MBenchmark::SListMapStruct& lms)
{
	START_TEST(init_listmap)
	auto& lmii = lms.lmii();
	auto& lmss = lms.lmss();
	string strV;
	for(int i=0;i<32;i++) strV.append("A");	
	for(int i=0;i<1024;i++)
	{
		MBenchmark::Int2IntMap mii;
		MBenchmark::Str2StrMap mss;
		for(int j=0;j<1024;j++)
		{
			int idj = j%32;
			string strK = strV +  i2str(j);
			mii[j]=1<<idj;
			mss[strK]=strV;
		}
		lmii.push_back(mii);
		lmss.push_back(mss);
	}
	END_TEST(init_listmap)
	cout<<"init_listmap,duration="<<dur<<" usec"<<endl;
}

void* run_listmap(void* arg)
{
	auto* lms = (MBenchmark::SListMapStruct*)arg;
	exec_sdl_seria(*lms);
	return NULL;
}

void test_listmap()
{
	cout<<"sdlbuffer test listmap"<<endl;
	MBenchmark::SListMapStruct lms;
	init_listmap(lms);
	multi_thread_exec(lms,run_listmap);
}



void init_listlist(MBenchmark::SListListStruct& llS)
{
	START_TEST(__func__)
	auto& lli = llS.lli();
	auto& lls = llS.lls();
	string strV;
	for(int i=0;i<32;i++) strV.append("A");	
	for(int i=0;i<1024;i++)
	{
		MBenchmark::IntList li;
		MBenchmark::StrList ls;
		for(int j=0;j<1024;j++)
		{
			int idj = j%32;
			li.push_back(1<<idj);
			ls.push_back(strV);
		}
		lli.push_back(li);
		lls.push_back(ls);
	}
	END_TEST(__func__)
	cout<<"init_listlist,duration="<<dur<<" usec"<<endl;
}
void* run_listlist(void* arg)
{
	auto* llS = (MBenchmark::SListListStruct*)arg;
	exec_sdl_seria(*llS);
	return NULL;
}
void test_listlist()
{
	cout<<"sdlbuffer test listlist"<<endl;
	MBenchmark::SListListStruct llS;
	init_listlist(llS);
	multi_thread_exec(llS,run_listlist);
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
	test_string();
	//test_map();
	//test_list();

	//test_maplist();
	//test_mapmap();
	//test_listmap();
	//test_listlist();
	return 0;
}
