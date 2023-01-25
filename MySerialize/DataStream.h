/*
���л���
�������������������С��һ�����͵ı�ʾ��
���л��ķ�ʽ���ǰѱ���ת��Ϊchar*���ͣ������ƣ�Ȼ����롣


*/

#pragma once

#include<vector>
#include <string>
using namespace std;

namespace LearnSerialize {
	namespace serialize {
		class Datastream {
		public:
            enum DataType
            {
                BOOL = 0,
                CHAR,
                INT32,
                INT64,
                FLOAT,
                DOUBLE,
                STRING,
                VECTOR,
                LIST,
                MAP,
                SET,
                CUSTOM
            };
            Datastream() {}
            ~Datastream(){}
            //����д�Ļ�����ʽ
            void write(const char* data,int len);
            //overloading all function in there 

            //32 bit int
            void write(int32_t value);
            // string in C
            void write( const char* value);
            // string in C++
            void write(const string & value);
            //�ӣ������� write����
            // 
            //����������
            Datastream & operator <<(int32_t value);
            //�ӣ��������͵����ز�������


            void reserve(int len);
            //����չʾbuffer������
            //�ӣ�ֻд��int32�ġ�
            void show() const ;
		private:
			std::vector<char>m_buf;
		};
        inline Datastream& Datastream::operator<<(int32_t value)
        {
            // TODO: �ڴ˴����� return ���
            write(value);
            return *this;
        }
        //�ֶ���buf����
        void Datastream::reserve(int len) {
            int size = m_buf.size();
            int cap = m_buf.capacity();
            if (size + len > cap) {
                while (size + len > cap) {
                    if (cap == 0) {
                        cap = 1;
                    }
                    else {
                        cap *= 2;
                    }
                }
                m_buf.reserve(cap);
            }
        }
        inline void Datastream::show() const
        {
            int len = m_buf.size();
            int i = 0;
            cout << "buffer's size is " << len << endl;
            while (i < len) {
                switch ((DataType)m_buf[i])
                {
                case DataType::INT32:
                    cout << *(int32_t*)&m_buf[++i] << endl;
                    i += 4;
                    break;
                default:
                    break;
                }
            }
        }
        void Datastream::write(const char* data, int len) {
            reserve(len);
            int size = m_buf.size();
            m_buf.resize(size + len);
            std::memcpy(&m_buf[size],data,len);
        }
        void Datastream::write(int32_t value) {
            char tp = DataType::INT32;
            write((char*)&tp, sizeof(char));
            write((char*)&value, sizeof(int));
        }
         void Datastream::write(const char* value)
        {
            char tp = DataType::STRING;
            write((char*)&tp, sizeof(char));
            int len = strlen(value);
            write(len);
            write(value, len);
        }
         inline void Datastream::write(const string& value)
         {
             char tp = DataType::STRING;
             write((char*)&tp, sizeof(char));
             int len = value.length();
             write(len);
             write(value.data(), len);
         }
}
}