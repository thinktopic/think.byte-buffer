#ifndef BYTE_BUFFER_HPP
#define BYTE_BUFFER_HPP

namespace think { namespace byte_buffer {

    using namespace std;

    struct EndianType {
      enum Enum {
	LittleEndian = 1,
	BigEndian = 2,
      };
    };

    struct Datatype {
      enum Enum {
	Byte = 0,
	Short,
	Int,
	Long,
	Float,
	Double,
      };
    };

    class BufferManager
    {
    public:
      virtual ~BufferManager(){}
      virtual int64_t allocate_buffer( int64_t size, const char* file, int line ) = 0;
      virtual void release_buffer( int64_t data) = 0;

      virtual void copy( int64_t src_data, Datatype::Enum src_type, int64_t src_offset,
			 unsigned char* dst, int64_t offset, int64_t n_elems ) = 0;
      virtual void copy( int64_t src_data, Datatype::Enum src_type, int64_t src_offset,
			 int16_t* dst, int64_t dst_offset, int64_t n_elems ) = 0;
      virtual void copy( int64_t src_data, Datatype::Enum src_type, int64_t src_offset,
			 int32_t* dst, int64_t dst_offset, int64_t n_elems ) = 0;
      virtual void copy( int64_t src_data, Datatype::Enum src_type, int64_t src_offset,
			 int64_t* dst, int64_t dst_offset, int64_t n_elems ) = 0;
      virtual void copy( int64_t src_data, Datatype::Enum src_type, int64_t src_offset,
			 float* dst, int64_t dst_offset, int64_t n_elems ) = 0;
      virtual void copy( int64_t src_data, Datatype::Enum src_type, int64_t src_offset,
			 double* dst, int64_t dst_offset, int64_t n_elems ) = 0;

      virtual void copy( const unsigned char* src, int64_t src_offset,
			 int64_t dst_data, Datatype::Enum dst_type, int64_t dst_offset, int64_t n_elems ) = 0;
      virtual void copy( const int16_t* src, int64_t src_offset,
			 int64_t dst_data, Datatype::Enum dst_type, int64_t dst_offset, int64_t n_elems ) = 0;
      virtual void copy( const int32_t* src, int64_t src_offset,
			 int64_t dst_data, Datatype::Enum dst_type, int64_t dst_offset, int64_t n_elems ) = 0;
      virtual void copy( const int64_t* src, int64_t src_offset,
			 int64_t dst_data, Datatype::Enum dst_type, int64_t dst_offset, int64_t n_elems ) = 0;
      virtual void copy( const float* src, int64_t src_offset,
			 int64_t dst_data, Datatype::Enum dst_type, int64_t dst_offset, int64_t n_elems ) = 0;
      virtual void copy( const double* src, int64_t src_offset,
			 int64_t dst_data, Datatype::Enum dst_type, int64_t dst_offset, int64_t n_elems ) = 0;


      virtual void copy( int64_t src_data, Datatype::Enum src_type, int64_t src_offset,
			 int64_t dst_data, Datatype::Enum dst_type, int64_t dst_offset, int64_t n_elems ) = 0;


      virtual void set_value( int64_t dst_data, Datatype::Enum dst_type,
			      int64_t offset, unsigned char value, int64_t n_elems ) = 0;
      virtual void set_value( int64_t dst_data, Datatype::Enum dst_type,
			      int64_t offset, int16_t value, int64_t n_elems ) = 0;
      virtual void set_value( int64_t dst_data, Datatype::Enum dst_type,
			      int64_t offset, int32_t value, int64_t n_elems ) = 0;
      virtual void set_value( int64_t dst_data, Datatype::Enum dst_type,
			      int64_t offset, int64_t value, int64_t n_elems ) = 0;
      virtual void set_value( int64_t dst_data, Datatype::Enum dst_type,
			      int64_t offset, float value, int64_t n_elems ) = 0;
      virtual void set_value( int64_t dst_data, Datatype::Enum dst_type,
			      int64_t offset, double value, int64_t n_elems ) = 0;

      virtual unsigned char get_value_int8( int64_t src_data, Datatype::Enum src_type, int64_t offset ) = 0;
      virtual int16_t get_value_int16( int64_t src_data, Datatype::Enum src_type, int64_t offset ) = 0;
      virtual int32_t get_value_int32( int64_t src_data, Datatype::Enum src_type, int64_t offset ) = 0;
      virtual int64_t get_value_int64( int64_t src_data, Datatype::Enum src_type, int64_t offset ) = 0;
      virtual float get_value_float( int64_t src_data, Datatype::Enum src_type, int64_t offset ) = 0;
      virtual double get_value_double( int64_t src_data, Datatype::Enum src_type, int64_t offset ) = 0;


      static BufferManager* create_buffer_manager();
      virtual void release_manager() = 0;
    };
}}

#endif
