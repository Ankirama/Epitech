import struct

def ushort_uint(buf):
    return(struct.unpack('>HI', buf))

def buf2latin(buf):
    value = struct.unpack('>h', buf[:2])[0]
    rule = str(value) + 's'
    return((value, struct.unpack_from(rule, buf, 2)[0].decode('latin1')))

def ascii2buf(*args):
    buf = bytearray()
    fmt = ">I"
    buf += struct.pack(fmt, len(args))
    for arg in args:
        fmt = ">H"
        buf += struct.pack(fmt, len(arg))
        buf += arg.encode('ascii')
    return(buf)