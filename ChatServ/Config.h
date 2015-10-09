

#ifndef __chatserv__Config__
#define __chatserv__Config__

/*
�﷨����:
�հ��ַ�Ϊ '\t \r\n'(�Ʊ��, �ո�, �س�, ����)
����ֻ�����հ��ַ�����
��Ч���� '\t*' ��ͷ
ע������ '\t*#' ��ͷ
key �� value ֮������õȺ�'='����ð��':'�ָ�
key �������κοհ��ַ�, ���˵Ŀհ��ַ�������
value ���˵Ŀհ��ַ�������
����������а�����ϵ, ��һ�� TAB ������ʾ���ӹ�ϵ

���ö�ȡ:
�ü�����ȡ��������
��б��'/'���߾��'.'�ָ���������·����ȡ������
���������ֵ��Ϊ����(int)����
���������ֵ��Ϊ�ַ���(char *)����
*/

#include <string>
#include <vector>

#define CONFIG_MAX_LINE		4096

/* special filenames: stdin, stdout, stderr */
class Config{
private:
	Config *parent;
	int depth;

	Config(const std::string &key = "", const std::string &val = ""){
		this->parent = NULL;
		this->depth = 0;
		this->key = key;
		this->val = val;
	};

	Config* add(const char *key, const char *val, int lineno);
	const Config* find_child(const char *key) const;
public:
	~Config();
	static Config* load(const char *filename);
	int save(FILE *fp) const;
	int save(const char *filename) const;

	std::vector<Config *> children;
	std::string key;
	std::string val;

	const Config* get(const char *key) const;
	int num() const;
	int get_num(const char *key) const;
	const char* str() const;
	const char* get_str(const char *key) const;

	bool is_comment() const{
		return key[0] == '#';
	}
	std::string ToString() const{
		return key + ": " + val;
	}
};

#endif
/* defined(__chatserv__Config__) */
