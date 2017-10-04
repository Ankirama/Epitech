//
// Created by Fabien Martinez on 01/06/15.
//

#ifndef CPP_BOMBERMAN_XMLWRITE_HH
#define CPP_BOMBERMAN_XMLWRITE_HH

/**
 * @file XmlWrite.hpp
 * @brief create xml file
 * @author ankirama
 * @version 1.01
 */

#include <sstream>
#include <iostream>
#include <string>
#include <stack>

#define VERSION "1.0"

/**
 * @enum t_typeField
 * @brief Constantes used to check type field
 *
 * Used in the controller's class
 */
typedef enum    e_typeField {
    FIELD_TAG_START,
    FIELD_TAG_END,
    FIELD_DATA,
    FIELD_ATTRIBUTE
}               t_typeField;

/**
 * @class XmlWrite
 * @brief Create and write into xml
 *
 * It will create a xml file and write into it with specific norm like a true xml
 */
class XmlWrite {
private:
  /**
   * @enum t_state
   * @brief Constantes used to define a state
   */
    typedef enum    e_state {
        NONE,
        ATTRIBUTE,
        TAG,
        TAG_NAME
    }               t_state;
public:

    /**
     * @class Controller
     * @brief Internal class to help XmlWrite
     *
     * It will allow us to get some infos like field type or current string
     */
    class  Controller {
    public:
      /**
       * @brief Controller's constructor
       *
       * @param type field type like DATA, TAG_START etc
       * @param str Not necessary but useful to define a name
       */
        Controller(const t_typeField type, const std::string& str = "") : m_typeField(type), m_str(str) {}

        /**
         * @brief Controller's constructor by copy
         *
         * @param copy Controller's reference we will copy
         */
        Controller(const Controller &copy) : m_typeField(copy.getField()), m_str(copy.getStr()) {}

        /**
         * @brief getter for str
         *
         * @return Get the str's reference stored into the instance
         */
        const std::string &getStr() const {return this->m_str;}

        /**
         * @brief getter for field type
         *
         * @return Get the field type stored into the instance
         */
        t_typeField getField() const {return this->m_typeField;}

        /**
         * @brief Controller's destructor
         */
        ~Controller() {}
    private:
        t_typeField m_typeField; /**< field type for our controller */
        std::string m_str; /**< string for our controller */

    private:

      /**
       * @brief private = operator to unable it
       *
       * Unused and undefined.
       */
        Controller& operator=(const Controller&);

        /**
         * @brief Controller's default constructor
         *
         * We don't need a default constructor so it's private
         */
        Controller();
    };
public:

    /**
     * @brief XmlWrite's constructor
     *
     * Stream initialized and we write the header in our xml file
     *
     * @param stream Reference in our file's stream used to write into it
     */
    XmlWrite(std::ostream &stream) : m_stream(stream), m_state(NONE) {
        m_stream << "<?xml version=\"" << VERSION << "\" encoding=\"UTF-8\"?>" << std::endl;
    }

    /**
     * @brief XmlWrite's destructor
     *
     * it will close every tag which aren't closed.
     */
    ~XmlWrite() {
      if (this->m_state == TAG_NAME) {
        this->m_stream << "/>";
        this->m_state = NONE;
      }
      while (!this->m_tags.empty())
        closeTag(this->m_tags.top());
    }

    /**
     * @brief template for <<
     *
     * It will allow us to write directly into our file wich any variable
     * @tparam value The list of value type like string, char*, int, ...
     * @return Current instance's reference to allow more than one <<
     */
    template<class T>
    XmlWrite& operator<<(const T& value) {
        if (this->m_state == TAG_NAME)
            this->m_tagStream << value;
        this->m_stream << value;
        return *this;
    }

    /**
     * @brief operator << to write our tag
     *
     * This is our main overload.
     * We will check the controller used and do something with its typeField
     * Switch between TAG_START / TAG_END / DATA / ATTRIBUTE
     *
     * @param controller a controller with a field type and a str
     * @return Current instance's reference to allow more than one <<
     */
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
    std::ostream            &m_stream; /**< our stream's reference used to write into the file */
    std::stack<std::string> m_tags; /**< tags' stack (LIFO) used to open/close tags */
    std::ostringstream      m_tagStream; /**< current tag/attribute stored in our instance */
    t_state                 m_state; /**< current state (init with NONE) used to to choose action with attribute */
private:

    /**
     * @brief XmlWrite's default constructor
     *
     * unused default constructor
     */
    XmlWrite();

    /**
     * @brief private = operator to unable it
     *
     * Unused and undefined
     */
    XmlWrite& operator=(const XmlWrite&);

    /**
     * @brief private copy constructor
     *
     * Unused
     */
    XmlWrite(const XmlWrite&);

    /**
     * @brief Close an open bracket
     *
     * It will close an open bracket like <"players
     * and will add '"' + '/' (if end is true) + '>'
     *
     * @param end default value is false and it used to add a '/'
     */
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

    /**
     * @brief Clean a stringstream
     *
     * It will clean the stringstream in the class
     */
    inline void cleanStringstream() {
        this->m_tagStream.str(std::string());
    }

    /**
     * @brief Close tags
     *
     * It will close all tags until the tag given or the end
     *
     * @param tag Close every tags until this tag
     */
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

/**
 * @brief create a tag named <tag>
 *
 * @param tag tag's name
 * @return Create a controller with TAG_START flag and return it
 */
inline const XmlWrite::Controller tag(const std::string& tag = "") {
    return XmlWrite::Controller(FIELD_TAG_START, tag);
}

/**
 * @brief close a tag named <tag>
 *
 * @param tag tag's name
 * @return Create a controller with TAG_END flag and return it
 */
inline const XmlWrite::Controller endtag(const std::string& tag = "") {
    return XmlWrite::Controller(FIELD_TAG_END, tag);
}

/**
 * @brief create an attribute named <attribute>
 *
 * @param attribute attribute's name
 * @return Create a controller with ATTRIBUTE flag and return it
 */
inline const XmlWrite::Controller attribute(const std::string& attribute) {
    return XmlWrite::Controller(FIELD_ATTRIBUTE, attribute);
}

/**
 * @brief add data into element
 *
 * @return Create a controller with DATA flag and return it
 */
inline const XmlWrite::Controller data() {
    return XmlWrite::Controller(FIELD_DATA);
}

#endif //CPP_BOMBERMAN_XMLWRITE_HH
