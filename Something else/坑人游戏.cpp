#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<cstdio>
using namespace std;
int score=0;
int random(int min,int max){
	srand(time(0)); 
	return rand()%(max-min+1)+min;
}
void winners(){
	freopen("坑人游戏.cpp","r",stdin);
	string s;
	while(getline(cin,s)){
		cout << s << endl;
	}
	cin.clear();
	freopen("CON","r",stdin);
}
void game(){
	string ans="",ans2="";
	int rwd1,rwd2;
	cout << "您现在在起点，眼前有一条岔路。您要往左走还是往右走？（回答往左走或往右走）";
	cin >> ans;
	if(ans=="往左走"){
		if(random(1,2)==1){
			cout << "此路不通，已返回起点。\n";
			game();
		} else{
			cout << "碰到一座山，您是要翻过去还是绕过去？（回答翻过去或绕过去）";
			cin >> ans;
			if(ans=="翻过去"){
				if(random(1,2)==1){
					cout << "您走了大半天，口干舌燥。正好眼前有一条小河，您喝吗？（回答喝或不喝）";
					cin >> ans;
					if(ans=="喝"){
						if(random(1,3)<3){
							cout << "哦，天哪！您竟然喝到了脏水，中毒死亡。您本局的金币为：" << score;
						} else{
							cout << "您又觉得头皮发痒，要洗澡吗？（回答洗澡或不洗）";
							cin >> ans;
							if(ans=="洗澡"){
								if(random(1,3)<3){
									cout << "您没注意到您的背后有条鳄鱼，被它咬死。您本局的金币为：" << score;
								} else{
									cout << "您洗了个澡，神清气爽。\n您走啊走，走到了鱿鱼游戏的现场。很幸运，您被选为了幸运观众。您要选择哪扇门，左边那扇、右边那扇还是中间那扇？（回答左、中或右）";
									rwd1=random(1,3);
									rwd2=rwd1;
									while(rwd2==rwd1){
										rwd2=random(1,3);
									}
									cin >> ans;
									if(ans=="左"){
										switch(rwd1){
											case 1:
												switch(rwd2){
													case 2:
														cout << "提示一下您，中间那扇门后面什么也没有哦！";
														break;
													case 3:
														cout << "提示一下您，右边那扇门后面什么也没有哦！";
												}
												break;
											case 2:
												switch(rwd2){
													case 1:
														cout << "提示一下您，中间那扇门后面什么也没有哦！";
														break;
													case 3:
														cout << "提示一下您，右边那扇门后面什么也没有哦！";
												}
											case 3:
												switch(rwd2){
													case 1:
														cout << "提示一下您，右边那扇门后面什么也没有哦！";
														break;
													case 2:
														cout << "提示一下您，中间那扇门后面什么也没有哦！";
												}
										} 
									} else if(ans=="中"){
										switch(rwd1){
											case 1:
												switch(rwd2){
													case 2:
														cout << "提示一下您，左边那扇门后面什么也没有哦！";
														break;
													case 3:
														cout << "提示一下您，右边那扇门后面什么也没有哦！";
												}
												break;
											case 2:
												switch(rwd2){
													case 1:
														cout << "提示一下您，左边那扇门后面什么也没有哦！";
														break;
													case 3:
														cout << "提示一下您，右边那扇门后面什么也没有哦！";
												}
											case 3:
												switch(rwd2){
													case 1:
														cout << "提示一下您，左边那扇门后面什么也没有哦！";
														break;
													case 2:
														cout << "提示一下您，右边那扇门后面什么也没有哦！";
												}
										} 
									} else if(ans=="右"){
										switch(rwd1){
											case 1:
												switch(rwd2){
													case 2:
														cout << "提示一下您，中间那扇门后面什么也没有哦！";
														break;
													case 3:
														cout << "提示一下您，左边那扇门后面什么也没有哦！";
												}
												break;
											case 2:
												switch(rwd2){
													case 1:
														cout << "提示一下您，左边那扇门后面什么也没有哦！";
														break;
													case 3:
														cout << "提示一下您，中间那扇门后面什么也没有哦！";
												}
											case 3:
												switch(rwd2){
													case 1:
														cout << "提示一下您，左边那扇门后面什么也没有哦！";
														break;
													case 2:
														cout << "提示一下您，中间那扇门后面什么也没有哦！";
												}
										} 
									} else{
										game();
									}
									cout << "你准备更改选择吗？（回答是或否）";
									cin >> ans2;
									if(ans2=="是"){
										cout << "您要选择哪扇门，左边那扇、右边那扇还是中间那扇？（回答左、中或右）";
										cin >> ans;
										if(ans=="左"){
										switch(rwd1){
											case 1:
												cout << "您选择的门后面什么也没有！您被气死了。您本局的金币是：" << score;
												return;
											case 2:
												switch(rwd2){
													case 1:
														cout << "您选择的门后面什么也没有！您被气死了。您本局的金币是：" << score;
														return;
													case 3:
														cout << "恭喜您，您获得了一个金币的奖励！您带着喜悦的心情走到了终点。恭喜您，您的金币加十，并且您还可以观看本坑人游戏的代码，";
														score+=10;
														winners();
														cout << "游戏胜利，您一身轻松。";
												}
											case 3:
												switch(rwd2){
													case 1:
														cout << "您选择的门后面什么也没有！您被气死了。您本局的金币是：" << score;
														return;
													case 2:
														cout << "恭喜您，您获得了一个金币的奖励！您带着喜悦的心情走到了终点。恭喜您，您的金币加十，并且您还可以观看本坑人游戏的代码，";
														score+=10;
														winners();
														cout << "游戏胜利，您一身轻松。";
												}
										} 
										} else if(ans=="中"){
										switch(rwd1){
											case 1:
												switch(rwd2){
													case 2:
														cout << "您选择的门后面什么也没有！您被气死了。您本局的金币是：" << score;
														return;
													case 3:
														cout << "恭喜您，您获得了一个金币的奖励！您带着喜悦的心情走到了终点。恭喜您，您的金币加十，并且您还可以观看本坑人游戏的代码，";
														score+=11;
														winners();
														cout << "游戏胜利，您一身轻松。";
														return;
												}
												break;
											case 2:
												cout << "您选择的门后面什么也没有！您被气死了。您本局的金币是：" << score;
												return;
											case 3:
												switch(rwd2){
													case 1:
														cout << "恭喜您，您获得了一个金币的奖励！您带着喜悦的心情走到了终点。恭喜您，您的金币加十，并且您还可以观看本坑人游戏的代码，";
														score+=11;
														winners();
														cout << "游戏胜利，您一身轻松。";
														return;
													case 2:
														cout << "您选择的门后面什么也没有！您被气死了。您本局的金币是：" << score;
														return;
												}
										} 
										} else if(ans=="右"){
											switch(rwd1){
												case 1:
													switch(rwd2){
														case 2:
															cout << "恭喜您，您获得了一个金币的奖励！您带着喜悦的心情走到了终点。恭喜您，您的金币加十，并且您还可以观看本坑人游戏的代码，";
															score+=11;
															winners();
															cout << "游戏胜利，您一身轻松。";
															return;
														case 3:
															cout << "您选择的门后面什么也没有！您被气死了。您本局的金币是：" << score;
															return;
													}
													break;
												case 2:
													switch(rwd2){
														case 1:
															cout << "恭喜您，您获得了一个金币的奖励！您带着喜悦的心情走到了终点。恭喜您，您的金币加十，并且您还可以观看本坑人游戏的代码，";
															score+=11;
															winners();
															cout << "游戏胜利，您一身轻松。";
														case 3:
															cout << "您选择的门后面什么也没有！您被气死了。您本局的金币是：" << score;
															return;
													}
												case 3:
													cout << "您选择的门后面什么也没有！您被气死了。您本局的金币是：" << score;
													return;
											} 
										} 
									} else if(ans2=="否"){
										if(ans=="左"){
										switch(rwd1){
											case 1:
												cout << "您选择的门后面什么也没有！您被气死了。您本局的金币是：" << score;
												return;
											case 2:
												switch(rwd2){
													case 1:
														cout << "您选择的门后面什么也没有！您被气死了。您本局的金币是：" << score;
														return;
													case 3:
														cout << "恭喜您，您获得了一个金币的奖励！您带着喜悦的心情走到了终点。恭喜您，您的金币加十，并且您还可以观看本坑人游戏的代码，";
														score+=10;
														winners();
														cout << "游戏胜利，您一身轻松。";
												}
											case 3:
												switch(rwd2){
													case 1:
														cout << "您选择的门后面什么也没有！您被气死了。您本局的金币是：" << score;
														return;
													case 2:
														cout << "恭喜您，您获得了一个金币的奖励！您带着喜悦的心情走到了终点。恭喜您，您的金币加十，并且您还可以观看本坑人游戏的代码，";
														score+=10;
														winners();
														cout << "游戏胜利，您一身轻松。";
												}
										} 
									} else if(ans=="中"){
										switch(rwd1){
											case 1:
												switch(rwd2){
													case 2:
														cout << "您选择的门后面什么也没有！您被气死了。您本局的金币是：" << score;
														return;
													case 3:
														cout << "恭喜您，您获得了一个金币的奖励！您带着喜悦的心情走到了终点。恭喜您，您的金币加十，并且您还可以观看本坑人游戏的代码，";
														score+=11;
														winners();
														cout << "游戏胜利，您一身轻松。";
														return;
												}
												break;
											case 2:
												cout << "您选择的门后面什么也没有！您被气死了。您本局的金币是：" << score;
												return;
											case 3:
												switch(rwd2){
													case 1:
														cout << "恭喜您，您获得了一个金币的奖励！您带着喜悦的心情走到了终点。恭喜您，您的金币加十，并且您还可以观看本坑人游戏的代码，";
														score+=11;
														winners();
														cout << "游戏胜利，您一身轻松。";
														return;
													case 2:
														cout << "您选择的门后面什么也没有！您被气死了。您本局的金币是：" << score;
														return;
												}
										} 
									} else if(ans=="右"){
										switch(rwd1){
											case 1:
												switch(rwd2){
													case 2:
														cout << "恭喜您，您获得了一个金币的奖励！您带着喜悦的心情走到了终点。恭喜您，您的金币加十，并且您还可以观看本坑人游戏的代码，";
														score+=11;
														winners();
														cout << "游戏胜利，您一身轻松。";
														return;
													case 3:
														cout << "您选择的门后面什么也没有！您被气死了。您本局的金币是：" << score;
														return;
												}
												break;
											case 2:
												switch(rwd2){
													case 1:
														cout << "恭喜您，您获得了一个金币的奖励！您带着喜悦的心情走到了终点。恭喜您，您的金币加十，并且您还可以观看本坑人游戏的代码，";
														score+=11;
														winners();
														cout << "游戏胜利，您一身轻松。";
													case 3:
														cout << "您选择的门后面什么也没有！您被气死了。您本局的金币是：" << score;
														return;
												}
											case 3:
												cout << "您选择的门后面什么也没有！您被气死了。您本局的金币是：" << score;
												return;
										} 
									} else{
										game();
									}
								}
							} 
						} else if(ans=="不洗"){
							cout << "于是您回到了起点洗澡。";
							game();
						} else{
							game();
						}
						} 
					} else if(ans=="不喝"){
						cout << "于是您回到了起点喝水。";
						game(); 
					} else{
						game();
					} 
				} else{
					cout << "您一不小心掉了下去，摔死了。您本局的金币为：" << score;
				}
			} else if(ans=="绕过去"){
				score++;
				cout << "恭喜您触碰到了一个幸运选择！金币加一。\n您走啊走啊，一直到晚上。您现在非常困，您想睡觉吗？（回答想或不想）";
				cin >> ans;
				if(ans=="想"){
					cout << "那么您想借宿吗？（回答想或不想）";
					cin >> ans;
					if(ans=="想"){
						if(random(1,2)==1){
							cout << "恭喜您，借宿成功！您可以安心的睡一宿了。\n";
							if(random(1,2)==1){
								cout << "第二天，下起了倾盆大雨。您猝手不及，淋雨感冒，不得不回起点休息。";
								game(); 
							} else{
								cout << "您在吃早餐时，椅子突然晃了一下。您被这么一惊，吃的饭没来得及下咽，被噎死了。您本局的金币为：" << score;
							}
						} else{
							cout << "您被别人赶了出去，心力交瘁，累死了。您本局的金币为：" << score;
						}
					} else if(ans=="不想"){
						cout << "于是您回到了起点睡觉。";
						game();
					} else{
						game();
					}
				} else if(ans=="不想"){
					cout << "您太困了，以至于被困死了。您本局的金币为：" << score;
				} else{
					game();
				}
			} else{
				game();
			}
		}
	} else if(ans=="往右走"){
		cout << "您走着走着，遇到了一家早餐店。您现在正饿着呢，要吃早餐吗？（回答吃或不吃）";
		cin >> ans;
		if(ans=="吃"){
			cout << "您吃完早餐，恰好看见一只鹿路过。您要跟着它吗？（回答是或否）";
			cin >> ans;
			if(ans=="是"){
				cout << "您跟着小鹿跑啊跑，跑到了终点。恭喜您，您的金币加十，并且您还可以观看本坑人游戏的代码，\n";
				score+=10;
				winners();
				cout << "游戏胜利，您一身轻松。";
			} else if(ans=="否"){
				cout << "您走啊走，看到了一条河。";
				if(random(1,2)==1){
					cout << "您正口渴着呢，要喝水吗？（回答是或否）";
					cin >> ans;
					if(ans=="是"){
						if(random(1,3)<3){
							cout << "啊！这水太脏了，您中毒死亡。您本局的金币为：" << score;
						} else{
							score++;
							cout << "恭喜您触碰到了一个幸运选择！金币加一。您走啊走，到达了终点。恭喜您，您的金币加十，并且您还可以观看本坑人游戏的代码，\n";
							score+=10;
							winners();
							cout << "游戏胜利，您一身轻松。";
						}
					} else if(ans=="否"){
						cout << "很不幸，您被渴死了。您本局的金币是：" << score;
					} else{
						game();
					}
				} else{
					cout << "您感觉头皮发痒，要洗澡吗？（回答是或否）";
					cin >> ans;
					if(ans=="是"){
						if(random(1,3)<3){
							cout << "您没注意到您的背后有条鳄鱼，被它咬死。您本局的金币为：" << score;
						} else{
							score+=2;
							cout << "恭喜您触碰到了一个幸运选择！金币加二。您遇到了一个乞丐。您要给钱吗？（注：和金币无关）（回答要或不要）";
							cin >> ans;
							if(ans=="要"){
								if(random(1,3)<3){
									cout << "乞丐很高兴，带着你走到了终点。恭喜您，您的金币加十，并且您还可以观看本坑人游戏的代码，\n";
									score+=10;
									winners();
									cout << "游戏胜利，您一身轻松。";
								} else{
									cout << "哎呀，您出门没带钱！您忧郁死了。您本局的金币是：" << score;
								}
							} else if(ans=="不要"){
								if(random(1,4)<4){
									cout << "乞丐恼羞成怒，把您打死了。您本局的金币是：" << score;
								} else{
									score+=2;
									cout << "恭喜您触碰到了一个幸运选择！金币加二。您继续走了大半天，饿了，于是您回起点吃饭去了。";
									game();
								}
							} else{
								game();
							}
						}
					} else if(ans=="否"){
						cout << "于是您回起点洗澡。";
						game();
					} else{
						game();
					}
				} 
			} else{
				game();
			}
		} else if(ans=="不吃"){
			if(random(1,2)==1){
				cout << "您走了大半天，饿了，但你旁边什么也没有，您就饿死了。您本局的金币是：" << score;
			} else{
				score++;
				cout << "恭喜您触碰到了一个幸运选择！金币加一。于是您回起点吃饭。";
				game(); 
			}
		} else{
			game();
		}
	} else{
		game();
	}
} 
int main(){
	srand(time(0));
	cout << "注意，如果不按要求回答，游戏会重启哦！\n游戏开始！\n";
	game();
	return 0;
}
