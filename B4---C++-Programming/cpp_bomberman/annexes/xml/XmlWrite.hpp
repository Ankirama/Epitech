//
// Created by Fabien Martinez on 01/06/15.
//

#ifndef CPP_BOMBERMAN_XMLWRITE_HH
#define CPP_BOMBERMAN_XMLWRITE_HH

#include <sstream>
#include <iostream>
#include <string>
#include <stack>

#define VERSION "0.1"

typedef enum    e_typeField {
    FIELD_TAG_START,
    FIELD_TAG_END,
    FIELD_DATA,
    FIELD_ATTRIBUTE
}               t_typeField;

class XmlWrite {
private:
    typedef enum    e_state {
        NONE,
        ATTRIBUTE,
        TAG,
        TAG_NAME
    }               t_state;
public:
    class  Controller {
    public:
        Controller(const t_typeField type, const std::string& str = "") : m_typeField(type), m_str(str) {}
        Controller(const Controller &copy) : m_typeField(copy.getField()), m_str(copy.getStr()) {}
        const std::string &getStr() const {return this->m_str;}
        t_typeField getField() const {return this->m_typeField;}
        ~Controller() {}
    private:
        t_typeField m_typeField;
        std::string m_str;

    private:
        Controller& operator=(const Controller&);
        Controller();
    };
public:
    XmlWrite(std::ostream &stream) : m_stream(stream), m_state(NONE) {
        m_stream << "<?xml version=\"" << VERSION << "\" encoding=\"UTF-8\"?>" << std::endl;
    }

    ~XmlWrite() {
      if (this->m_state == TAG_NAME) {
        this->m_stream << "/>";
        this->m_state = NONE;
      }
      while (!this->m_tags.empty())
        closeTag(this->m_tags.top());
    }

    template<class T>
    XmlWrite& operator<<(const T& value) {
        if (this->m_state == TAG_NAME)
            this->m_tagStream << value;
        this->m_stream << value;
        return *this;
    }

    XmlWrite& operator<<(const Controller& controller) {
        switch (controller.getField()) {
            case FIELD_TAG_START:
                closeBracketStart();
                this->m_stream << "<";
                if (!controller.getStr().empty()) {
                    this->m_stream << controller.getStr();
                    this->m_tags.push(controller.getStr());
                    this->m_state = TAG;
                }
                else {
                  cleanStringstream();
                  this->m_state = TAG_NAME;
                }
                break;
            case FIELD_TAG_END:
                closeTag(controller.getStr());
                break;
            case FIELD_DATA:
                closeBracketStart();
                this->m_state = NONE;
                break;
            case FIELD_ATTRIBUTE:
                switch (this->m_state) {
                    case TAG_NAME:
                        this->m_tags.push(this->m_tagStream.str());
                        break;
                    case ATTRIBUTE:
                        this->m_stream << "\"";
		default:
		  break;
                }
                if (this->m_state != NONE) {
                    this->m_stream << " " << controller.getStr() << "=\"";
                    this->m_state = ATTRIBUTE;
                }
                break;
        }
        return *this;
    }
private:
    std::ostream            &m_stream;
    std::stack<std::string> m_tags;
    std::ostringstream      m_tagStream;
    t_state                 m_state;
private:
    XmlWrite();
    XmlWrite& operator=(const XmlWrite&);
    XmlWrite(const XmlWrite&);

    void closeBracketStart(bool end = false) {
      if (this->m_state == TAG_NAME)
        this->m_tags.push(this->m_tagStream.str());
      switch (this->m_state) {
        case ATTRIBUTE:
          this->m_stream << "\"";
        case TAG :
        case TAG_NAME :
          if (end)
            this->m_stream << "/";
          this->m_stream << ">";
      default:
	break;
      }
    }

    inline void cleanStringstream() {
        this->m_tagStream.str(std::string());
    }

    void closeTag(const std::string& tag) {
        bool stop = false;

        while (!this->m_tags.empty() && !stop) {
            if (this->m_state == NONE)
                this->m_stream << "</" << this->m_tags.top() << ">";
            else {
                closeBracketStart(true);
                this->m_state = NONE;
            }
            stop = tag.empty() || tag == this->m_tags.top();
            this->m_tags.pop();
        }
    }
};

const XmlWrite::Controller tag() {
    return XmlWrite::Controller(FIELD_TAG_START);
}

const XmlWrite::Controller tag(const std::string& tag) {
    return XmlWrite::Controller(FIELD_TAG_START, tag);
}

const XmlWrite::Controller endtag() {
    return XmlWrite::Controller(FIELD_TAG_END);
}

const XmlWrite::Controller endtag(const std::string& tag) {
    return XmlWrite::Controller(FIELD_TAG_END, tag);
}

const XmlWrite::Controller attribute(const std::string& attribute) {
    return XmlWrite::Controller(FIELD_ATTRIBUTE, attribute);
}

const XmlWrite::Controller data() {
    return XmlWrite::Controller(FIELD_DATA);
}

#endif //CPP_BOMBERMAN_XMLWRITE_HH
