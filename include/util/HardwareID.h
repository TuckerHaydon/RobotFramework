/* 
 * Created by Tucker Haydon on 8/23/17. 
 */

#pragma once

#include <stdint.h>

/**
 * Wrapper class for unique hardware identifiers. Provides a check for null or uninitialized IDs.
 */
class HardwareID {
public:
    /**
     * Default constructor. Initializes the ID with the NULL_ID.
     */
    HardwareID();

    /**
     * Constructor.
     * @param ID Identifying parameter. Generally, should be unique.
     */
    HardwareID(const uint16_t &ID);

    /**
     * Returns Whether the ID is null or uninitialized.
     * @return Whether the ID is null or uninitialized.
     */
    bool isNull();

    /**
     * Equality operator. Checks that the internal IDs are equivalent.
     * @param other A different ID to compare to.
     * @return Whether or not this ID is equivalent to another.
     */
    bool operator ==(const HardwareID &other) const;

    /**
    * Inequality operator. Checks that the internal IDs are not equivalent.
    * @param other A different ID to compare to.
    * @return Whether or not this ID is not equivalent to another.
    */
    bool operator !=(const HardwareID &other) const;

    /**
    * Comparision operator. Checks that the internal IDs are equivalent.
    * @param other A different ID to compare to.
    * @return Whether or not this ID is equivalent to another.
    */
    bool operator <(const HardwareID &other) const;

    /**
    * Null ID constant
    */
    static const uint16_t NULL_ID;

private:
    /**
     * ID variable
     */
    uint16_t ID_;
};