/* syntax version 1 */
SELECT YQL::@@(block '(
	(let inputRows (AsList
		(AsStruct '('Data (String '"Input line #13")))
		(AsStruct '('Data (String '"Input line #35")))
		(AsStruct '('Data (String '"Input line #76")))
		(AsStruct '('Data (String '"Input line #70")))
		(AsStruct '('Data (String '"Input line #9")))
		(AsStruct '('Data (String '"Input line #63")))
		(AsStruct '('Data (String '"Input line #53")))
		(AsStruct '('Data (String '"Input line #89")))
		(AsStruct '('Data (String '"Input line #31")))
		(AsStruct '('Data (String '"Input line #4")))
		(AsStruct '('Data (String '"Input line #65")))
		(AsStruct '('Data (String '"Input line #64")))
		(AsStruct '('Data (String '"Input line #37")))
		(AsStruct '('Data (String '"Input line #79")))
		(AsStruct '('Data (String '"Input line #51")))
		(AsStruct '('Data (String '"Input line #59")))
		(AsStruct '('Data (String '"Input line #67")))
		(AsStruct '('Data (String '"Input line #98")))
		(AsStruct '('Data (String '"Input line #94")))
		(AsStruct '('Data (String '"Input line #55")))
		(AsStruct '('Data (String '"Input line #80")))
		(AsStruct '('Data (String '"Input line #96")))
		(AsStruct '('Data (String '"Input line #27")))
		(AsStruct '('Data (String '"Input line #29")))
		(AsStruct '('Data (String '"Input line #84")))
		(AsStruct '('Data (String '"Input line #77")))
		(AsStruct '('Data (String '"Input line #19")))
		(AsStruct '('Data (String '"Input line #22")))
		(AsStruct '('Data (String '"Input line #21")))
		(AsStruct '('Data (String '"Input line #49")))
		(AsStruct '('Data (String '"Input line #93")))
		(AsStruct '('Data (String '"Input line #61")))
		(AsStruct '('Data (String '"Input line #71")))
		(AsStruct '('Data (String '"Input line #15")))
		(AsStruct '('Data (String '"Input line #92")))
		(AsStruct '('Data (String '"Input line #50")))
		(AsStruct '('Data (String '"Input line #14")))
		(AsStruct '('Data (String '"Input line #99")))
		(AsStruct '('Data (String '"Input line #57")))
		(AsStruct '('Data (String '"Input line #10")))
		(AsStruct '('Data (String '"Input line #73")))
		(AsStruct '('Data (String '"Input line #54")))
		(AsStruct '('Data (String '"Input line #43")))
		(AsStruct '('Data (String '"Input line #17")))
		(AsStruct '('Data (String '"Input line #34")))
		(AsStruct '('Data (String '"Input line #36")))
		(AsStruct '('Data (String '"Input line #45")))
		(AsStruct '('Data (String '"Input line #30")))
		(AsStruct '('Data (String '"Input line #72")))
		(AsStruct '('Data (String '"Input line #90")))
		(AsStruct '('Data (String '"Input line #47")))
		(AsStruct '('Data (String '"Input line #86")))
		(AsStruct '('Data (String '"Input line #56")))
		(AsStruct '('Data (String '"Input line #38")))
		(AsStruct '('Data (String '"Input line #52")))
		(AsStruct '('Data (String '"Input line #42")))
		(AsStruct '('Data (String '"Input line #1")))
		(AsStruct '('Data (String '"Input line #82")))
		(AsStruct '('Data (String '"Input line #48")))
		(AsStruct '('Data (String '"Input line #75")))
		(AsStruct '('Data (String '"Input line #40")))
		(AsStruct '('Data (String '"Input line #85")))
		(AsStruct '('Data (String '"Input line #58")))
		(AsStruct '('Data (String '"Input line #33")))
		(AsStruct '('Data (String '"Input line #12")))
		(AsStruct '('Data (String '"Input line #46")))
		(AsStruct '('Data (String '"Input line #8")))
		(AsStruct '('Data (String '"Input line #44")))
		(AsStruct '('Data (String '"Input line #18")))
		(AsStruct '('Data (String '"Input line #25")))
		(AsStruct '('Data (String '"Input line #11")))
		(AsStruct '('Data (String '"Input line #2")))
		(AsStruct '('Data (String '"Input line #5")))
		(AsStruct '('Data (String '"Input line #3")))
		(AsStruct '('Data (String '"Input line #23")))
		(AsStruct '('Data (String '"Input line #20")))
		(AsStruct '('Data (String '"Input line #83")))
		(AsStruct '('Data (String '"Input line #6")))
		(AsStruct '('Data (String '"Input line #78")))
		(AsStruct '('Data (String '"Input line #95")))
		(AsStruct '('Data (String '"Input line #0")))
		(AsStruct '('Data (String '"Input line #16")))
		(AsStruct '('Data (String '"Input line #88")))
		(AsStruct '('Data (String '"Input line #28")))
		(AsStruct '('Data (String '"Input line #81")))
		(AsStruct '('Data (String '"Input line #60")))
		(AsStruct '('Data (String '"Input line #41")))
		(AsStruct '('Data (String '"Input line #24")))
		(AsStruct '('Data (String '"Input line #87")))
		(AsStruct '('Data (String '"Input line #26")))
		(AsStruct '('Data (String '"Input line #97")))
		(AsStruct '('Data (String '"Input line #91")))
		(AsStruct '('Data (String '"Input line #66")))
		(AsStruct '('Data (String '"Input line #69")))
		(AsStruct '('Data (String '"Input line #74")))
		(AsStruct '('Data (String '"Input line #7")))
		(AsStruct '('Data (String '"Input line #68")))
		(AsStruct '('Data (String '"Input line #39")))
		(AsStruct '('Data (String '"Input line #32")))
		(AsStruct '('Data (String '"Input line #62")))
	))

	(let udf (Udf '"Streaming.Process"))
	(let args1 (AsList (String '"[123679]")))
	(let res1 (Apply udf (Iterator inputRows) (String '"grep") args1))

	(let args2 (AsList (String '"4")))
	(let res2 (Apply udf res1 (String '"grep") args2))

	(let res3 (Apply udf res2 (String '"head")))

	(return (Collect res3))
))@@;
