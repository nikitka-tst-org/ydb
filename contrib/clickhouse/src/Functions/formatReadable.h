#pragma once

#include <Functions/IFunction.h>
#include <Functions/FunctionHelpers.h>
#include <Columns/ColumnString.h>
#include <Columns/ColumnVector.h>
#include <DataTypes/DataTypeString.h>
#include <IO/WriteBufferFromVector.h>
#include <IO/WriteHelpers.h>
#include <Interpreters/Context_fwd.h>


namespace DB
{

namespace ErrorCodes
{
    extern const int ILLEGAL_TYPE_OF_ARGUMENT;
    extern const int ILLEGAL_COLUMN;
}


/** formatReadableSize - prints the transferred size in bytes in form `123.45 GiB`.
  * formatReadableQuantity - prints the quantity in form of 123 million.
  */

template <typename Impl>
class FunctionFormatReadable : public IFunction
{
public:
    static constexpr auto name = Impl::name;
    static FunctionPtr create(ContextPtr) { return std::make_shared<FunctionFormatReadable<Impl>>(); }

    String getName() const override
    {
        return name;
    }

    bool isSuitableForShortCircuitArgumentsExecution(const DataTypesWithConstInfo & /*arguments*/) const override
    {
        return true;
    }

    size_t getNumberOfArguments() const override { return 1; }

    DataTypePtr getReturnTypeImpl(const DataTypes & arguments) const override
    {
        const IDataType & type = *arguments[0];

        if (!isNativeNumber(type))
            throw Exception(ErrorCodes::ILLEGAL_TYPE_OF_ARGUMENT, "Cannot format {} because it's not a native numeric type", type.getName());

        return std::make_shared<DataTypeString>();
    }

    bool useDefaultImplementationForConstants() const override { return true; }

    ColumnPtr executeImpl(const ColumnsWithTypeAndName & arguments, const DataTypePtr &, size_t /*input_rows_count*/) const override
    {
        ColumnPtr res;
        if (!((res = executeType<UInt8>(arguments))
            || (res = executeType<UInt16>(arguments))
            || (res = executeType<UInt32>(arguments))
            || (res = executeType<UInt64>(arguments))
            || (res = executeType<Int8>(arguments))
            || (res = executeType<Int16>(arguments))
            || (res = executeType<Int32>(arguments))
            || (res = executeType<Int64>(arguments))
            || (res = executeType<Float32>(arguments))
            || (res = executeType<Float64>(arguments))))
            throw Exception(ErrorCodes::ILLEGAL_COLUMN, "Illegal column {} of argument of function {}",
                            arguments[0].column->getName(), getName());

        return res;
    }

private:
    template <typename T>
    ColumnPtr executeType(const ColumnsWithTypeAndName & arguments) const
    {
        if (const ColumnVector<T> * col_from = checkAndGetColumn<ColumnVector<T>>(arguments[0].column.get()))
        {
            auto col_to = ColumnString::create();

            const typename ColumnVector<T>::Container & vec_from = col_from->getData();
            ColumnString::Chars & data_to = col_to->getChars();
            ColumnString::Offsets & offsets_to = col_to->getOffsets();
            size_t size = vec_from.size();
            data_to.resize(size * 2);
            offsets_to.resize(size);

            WriteBufferFromVector<ColumnString::Chars> buf_to(data_to);

            for (size_t i = 0; i < size; ++i)
            {
                Impl::format(static_cast<double>(vec_from[i]), buf_to);
                writeChar(0, buf_to);
                offsets_to[i] = buf_to.count();
            }

            buf_to.finalize();
            return col_to;
        }

        return nullptr;
    }
};

}
