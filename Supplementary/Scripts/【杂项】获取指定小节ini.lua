local box = select_box:new("ѡ���ȡ�ļ�")
box:add_option("fadata")
box:add_option("rules")
box:add_option("rules+map")
box:add_option("map")
box:add_option("art")
box:add_option("sound")
box:add_option("theme")
box:add_option("ai")
box:add_option("ai+map")
box:add_option("eva")
box:add_option("theater")
box:add_option("�������ֶ������ļ�����")

local load_from = box:do_modal()
if load_from == "�������ֶ������ļ�����" then
	load_from = input_box("�������ļ������������ϷĿ¼��������չ����")
end
local sections = get_sections(load_from)
local box2 = select_box:new("ѡ��С��")
for i,sec in pairs(sections) do
	if sec ~= "" then
		box2:add_option(sec)
	end
end
local section = box2:do_modal()
local kvps = get_key_value_pairs(section, load_from)
local output = "�����\n["..section.."]\n"
for k,v in pairs(kvps) do
	output = output..k.."="..v.."\n"
end
print(output)
