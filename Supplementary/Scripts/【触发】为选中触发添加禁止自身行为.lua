box = multi_select_box:new("��ѡ�񴥷�")
for i,id in pairs(get_keys("Triggers")) do
	box:add_option(id, get_param("Triggers", id, 3))
end
selected_triggers = box:do_modal()
print("Ϊ���д�������˽�ֹ������Ϊ��")
for i,id in pairs(selected_triggers) do
	trigger = get_trigger(id)
	trigger:add_action("54,2,"..id..",0,0,0,0,A")
	trigger:apply()
	print(get_param("Triggers", id, 3))
end