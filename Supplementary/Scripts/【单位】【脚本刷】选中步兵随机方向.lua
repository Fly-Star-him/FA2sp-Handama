function get_random_facing()
	facings = {0,32,64,96,128,160,192,224}
	return facings[math.random(1,8)]
end

if running_lua_brush() then
	for i=1,3 do
		local obj = get_infantry(X, Y, i)
		remove_infantry(X, Y, i)
		obj.facing = tostring(get_random_facing())
		obj:place()
	end
else
	message_box("���ű�����ͨ�����ű�ˢ�����У�", "����", 8)
end